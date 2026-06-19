*This project was created as part of the 42 curriculum by aramos-m.*

# Philosophers

## Description

<!--
2-3 párrafos. Cubrir:
- Qué es el problema clásico de los filósofos comensales (1 línea, Dijkstra).
- Qué pide la parte obligatoria: N hilos (un filósofo por hilo), un mutex por
  tenedor, simulación termina cuando alguien muere o cuando todos han comido
  N veces (si se da el 5º argumento).
- Una línea sobre lo que aprendiste tú: threads + mutex + medición de tiempo
  con gettimeofday + evitar data races.
- NO copies el enunciado. Explícalo con tus palabras.
-->

## Instructions

### Build

```bash
cd philo
make
```

Compiles with `-Wall -Werror -Wextra`. The default `make` rule produces the
`philo` binary.

### Run

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

| Argument | Unit | Meaning |
|---|---|---|
| number_of_philosophers | — | <!-- describe --> |
| time_to_die | ms | <!-- describe --> |
| time_to_eat | ms | <!-- describe --> |
| time_to_sleep | ms | <!-- describe --> |
| number_of_times_each_philosopher_must_eat | — | optional; simulation stops when every philosopher has eaten this many times |

### Examples

<!--
Pon 3-4 invocaciones reales que hayas probado, incluyendo:
- El caso 1 filósofo: ./philo 1 800 200 200
- Un caso que no debería morir nunca: ./philo 5 800 200 200
- Un caso que debe morir: ./philo 4 310 200 100
- Uno con meal_count: ./philo 5 800 200 200 7
-->

### Make targets

- `make` / `make all` — builds `philo`
- `make clean` — removes object files
- `make fclean` — removes object files and the binary
- `make re` — fclean + all

## Resources

### References

<!--
Lista SOLO lo que de verdad consultaste. Candidatos típicos:
- `man pthread_create`, `man pthread_mutex_lock`, `man gettimeofday`, `man usleep`
- Wikipedia: Dining philosophers problem (statement, no solution)
- Cualquier vídeo, post o paper que te ayudara — cítalo
-->

### AI usage

<!--
Esta sección la rellenas DESDE ai_log.md. Estructura sugerida:

**Tool used:** Claude (Anthropic), via web interface, as a tutor.

**What I used it for:**
- Conceptual explanations (mutex semantics, memory ordering intuition,
  why usleep is unreliable for fine-grained timing, race conditions on
  meal counters and death checks).
- Code review of code I had already written: detecting potential data
  races, missing unlocks, norm issues, leaks.
- Test case design (which argument combinations stress the death timing,
  how to read helgrind output).
- Structuring this README.

**What I did NOT use it for:**
- Writing functions for me. No AI-generated C code was pasted into this
  repository. Every line in `philo/*.c` and `philo/*.h` was typed by me
  after understanding the design.
- Debugging by paste-and-pray: when I asked about a bug, I described the
  symptom and reasoning, not "fix this for me".

**Where in the project:** see `ai_log.md` at the repository root for a
per-interaction log of topic, query summary, what I applied, and what I
learned.
-->