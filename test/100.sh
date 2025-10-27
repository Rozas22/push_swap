#!/usr/bin/env bash
set -euo pipefail
RUNS=${1:-30}

sum=0
best=
worst=
worst_arg=""
ok=0

for ((i=1; i<=RUNS; i++)); do
  ARG="$(python3 - <<'PY'
import random
print(*random.sample(range(-100000,100001), 100))
PY
)"
  OPS="$(./push_swap $ARG || true)"
  RES="$(printf "%s\n" "$OPS" | ./checker_linux $ARG || true)"
  N="$(printf "%s\n" "$OPS" | wc -l)"
  echo "$i) $RES  ops=$N"

  if [ "$RES" != "OK" ]; then
    echo "FAIL: checker != OK"; echo "Input: $ARG"; exit 1
  fi
  if (( N >= 1500 )); then
    echo "FAIL: ops=$N ≥ 1500"; echo "Input: $ARG"; exit 1
  fi

  ok=$((ok+1))
  sum=$((sum+N))

  # actualizar best/worst de forma robusta
  if [ -z "${best:-}" ] || (( N < best )); then best="$N"; fi
  if [ -z "${worst:-}" ] || (( N > worst )); then worst="$N"; worst_arg="$ARG"; fi
done

avg=$(awk -v s="$sum" -v n="$ok" 'BEGIN{ if(n>0) printf("%.2f", s/n); else print "n/a" }')
echo "Runs OK: $ok/$RUNS"
echo "Best:  ${best:-n/a}  Worst: ${worst:-n/a}  Avg: $avg"
echo "Worst input:"
echo "$worst_arg"

score=0
if   [ -n "${worst:-}" ] && (( worst < 700 ));   then score=5
elif [ -n "${worst:-}" ] && (( worst < 900 ));   then score=4
elif [ -n "${worst:-}" ] && (( worst < 1100 ));  then score=3
elif [ -n "${worst:-}" ] && (( worst < 1300 ));  then score=2
elif [ -n "${worst:-}" ] && (( worst < 1500 ));  then score=1
fi
echo "Score (100 nums, por peor caso): $score"
