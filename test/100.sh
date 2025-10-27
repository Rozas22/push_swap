#!/usr/bin/env bash
set -euo pipefail
RUNS=${1:-30}
sum=0; best=1e9; worst=0; worst_arg=""; ok=0

for ((i=1;i<=RUNS;i++)); do
  ARG="$(python3 - <<'PY'
import random; print(*random.sample(range(-100000,100001),100))
PY
)"
  OPS="$(./push_swap $ARG || true)"
  RES="$(printf "%s\n" "$OPS" | ./checker_linux $ARG || true)"
  N="$(printf "%s\n" "$OPS" | wc -l)"
  echo "$i) $RES  ops=$N"
  if [ "$RES" != "OK" ]; then
    echo "FAIL: checker != OK"; echo "Input: $ARG"; exit 1
  fi
  if [ "$N" -ge 1500 ]; then
    echo "FAIL: ops=$N >= 1500"; echo "Input: $ARG"; exit 1
  fi
  ok=$((ok+1)); sum=$((sum+N))
  (( N < best )) && best=$N
  if (( N > worst )); then worst=$N; worst_arg="$ARG"; fi
done

avg=$(awk -v s="$sum" -v n="$ok" 'BEGIN{ printf("%.2f", s/n) }')
echo "Runs OK: $ok/$RUNS"
echo "Best:  $best  Worst: $worst  Avg: $avg"
score=0
if   (( worst < 700 ));  then score=5
elif (( worst < 900 ));  then score=4
elif (( worst < 1100 )); then score=3
elif (( worst < 1300 )); then score=2
elif (( worst < 1500 )); then score=1
fi
echo "Score (100 nums, por peor caso): $score"
