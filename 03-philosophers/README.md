*This project was created as part of the 42 curriculum by aramos-m.*

# Philosophers

## Description

<!--
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
3-4 casos que haya probado:
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

- Wikipedia - Dining philosophers problem: [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- `man pthread_create`, `man pthread_mutex_lock`, `man gettimeofday`, `man usleep`

### AI usage

<!--
**Tool used:**
**What I used it for:**
-->