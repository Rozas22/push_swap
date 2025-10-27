# push_swap

Implementación del proyecto **push_swap** (42). Este ejecutable recibe una lista de enteros y devuelve por `stdout` la **secuencia mínima posible** (dentro de lo razonable) de operaciones para ordenar la pila **a** según las reglas del subject.

---

## ✅ Comprobaciones rápidas de errores (push_swap)

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
```
### 🧼 Comprobaciones de errores con Valgrind
```bash

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
  ```
### 🧪 Tests automáticos (carpeta test/)
En test/ hay dos scripts para validar rendimiento y corrección usando checker_linux:

test_100.sh → 100 números aleatorios repetidos N veces. Calcula Best/Worst/Avg y puntúa según la escala oficial de 100.

test_500.sh → 500 números aleatorios repetidos N veces. Calcula Best/Worst/Avg y puntúa según la escala oficial de 500.

Requisitos

Tener checker_linux en el directorio del proyecto (o ajustar la ruta en los scripts).

Tener Python 3 instalado (se usa para generar entradas aleatorias sin duplicados).

Ejecutar con bash.
```bash
📁 Estructura
bash
Copiar código
test/
├─ test_100.sh
└─ test_500.sh
▶️ Cómo ejecutarlos
bash
Copiar código
# Desde la raíz del repo
chmod +x test/test_100.sh test/test_500.sh

# 30 repeticiones de 100 números (por defecto 30 si no pasas argumento)
bash test/test_100.sh 30

# 10 repeticiones de 500 números (por defecto 10 si no pasas argumento)
bash test/test_500.sh 10
```
📊 Qué muestran
checker: OK/KO por cada ejecución.

ops: número de instrucciones emitidas por push_swap.

Best / Worst / Avg: mejor, peor y media de operaciones.

Score: nota final según el peor caso del lote.

🏁 Escalas de puntuación
Para 100 números (el test falla si alguna ejecución tiene ≥ 1500 ops):

< 700 → 5 puntos

< 900 → 4 puntos

< 1100 → 3 puntos

< 1300 → 2 puntos

< 1500 → 1 punto

Para 500 números (el test falla si alguna ejecución tiene ≥ 11500 ops):

< 5500 → 5 puntos

< 7000 → 4 puntos

< 8500 → 3 puntos

< 10000 → 2 puntos

< 11500 → 1 punto

El script imprime también el input peor para poder reproducirlo y depurarlo.

### 🛠️ Ejecución manual rápida (sin script)
```bash
Copiar código
# 100 números, una ejecución
ARG="$(python3 - <<'PY'
import random; print(*random.sample(range(-100000,100001), 100))
PY
)"; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l

# 500 números, una ejecución
ARG="$(python3 - <<'PY'
import random; print(*random.sample(range(-2147483648,2147483647), 500))
PY
)"; ./push_swap $ARG | ./checker_linux $ARG; ./push_swap $ARG | wc -l
```
### 📌 Consejos y resolución de problemas
Salida estricta: imprime solo instrucciones válidas (sa, pb, ra, …) en minúsculas y una por línea (\n). Nada de \r, espacios extra o logs.

Orden de carga: el primer argumento debe ser la cima de a. Construye la pila conservando el orden de entrada.

is_sorted: comprueba ascendente de TOP→BOTTOM y que b esté vacía al final.

Leaks: usa Valgrind (ver arriba). Objetivo: definitely lost: 0 bytes.

Rendimiento: para inputs grandes, usa radix por índices comprimidos (0..n-1) con número de bits mínimo y evita rotaciones extra.

