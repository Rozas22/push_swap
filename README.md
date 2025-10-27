# push_swap

## Comprobaciones rápidas de errores (push_swap)

> Reglas del subject:
> - Si hay error en los argumentos → **imprimir `Error\n` por _stderr_**.
> - Si no hay parámetros → **no imprimir nada**.
> - Errores típicos: **no numérico**, **duplicado**, **fuera de rango `int`**.

### Ver exactamente lo que imprime mi programa
```bash
# No numérico
./push_swap 0 one 2 3

# Duplicado
./push_swap 2 3 3

# Fuera de rango (mayor que INT_MAX / menor que INT_MIN)
./push_swap 2147483648
./push_swap -2147483649

# Sin parámetros (no debe imprimir nada)
./push_swap

### Comprobaciónes errores con Valgrind

# No numérico
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  --log-file=vg-nonnum.txt -- ./push_swap 0 one 2 3 >/dev/null 2>&1

# Duplicado
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  --log-file=vg-dup.txt -- ./push_swap 2 3 3 >/dev/null 2>&1

# Fuera de rango
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  --log-file=vg-over.txt -- ./push_swap 2147483648 >/dev/null 2>&1

# Sin parámetros (no debe imprimir nada)
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
  --log-file=vg-noparams.txt -- ./push_swap >/dev/null 2>&1
