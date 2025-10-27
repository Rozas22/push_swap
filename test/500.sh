#!/usr/bin/env bash
set -euo pipefail
RUNS=${1:-10}

sum=0; best=1000000000; worst=0; worst_arg=""; ok=0

for ((i=1;i<=RUNS;i++)); do
  ARG="$(python3 - <<'PY'
import random
print(*random.sample(range(-2147483648,2147483647), 500))
PY
)"
  OPS="$(./push_swap $ARG || true)"
  RES="$(printf "%s\n" "$OPS" | ./checker_linux $ARG || true)"
  N="$(printf "%s\n" "$OPS" | wc -l)"

  echo "$i) $RES  ops=$N"
  if [ "$RES" != "OK" ]; then
    echo "FAIL: checker != OK"; echo "Input: $ARG"; exit 1
  fi
  if (( N >= 11500 )); then
    echo "FAIL: ops=$N >= 11500 (0 puntos)"; echo "Input: $ARG"; exit 1
  fi

  ok=$((ok+1)); sum=$((sum+N))
  (( N < best )) && best=$N
  if (( N > worst )); then worst=$N; worst_arg="$ARG"; fi
done

avg=$(awk -v s="$sum" -v n="$ok" 'BEGIN{ if(n>0) printf("%.2f", s/n); else print "n/a" }')
echo "Runs OK: $ok/$RUNS"
echo "Best:  $best  Worst: $worst  Avg: $avg"
echo "Worst input:"
echo "$worst_arg"

# Escala de 500 números:
# <5500:5 | <7000:4 | <8500:3 | <10000:2 | <11500:1
score=0
if   (( worst < 5500 ));   then score=5
elif (( worst < 7000 ));   then score=4
elif (( worst < 8500 ));   then score=3
elif (( worst < 10000 ));  then score=2
elif (( worst < 11500 ));  then score=1
fi
echo "Score (500 nums, por peor caso): $score"


