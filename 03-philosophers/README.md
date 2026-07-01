*This project was created as part of the 42 curriculum by aramos-m.*

# Philosophers

## Description

This project is an implementation of the classic **dining philosophers**
synchronization problem. A number of philosophers sit around a table, sharing
one fork between each pair of neighbours. Each philosopher alternates between
eating, sleeping and thinking, and must never starve.

The goal is to learn the basics of threading and synchronization in C: each
philosopher runs in its own thread, every fork is protected by a mutex, and a
dedicated monitor thread watches for starvation and stops the simulation as
soon as a philosopher dies (or once everyone has eaten enough). There are no
global variables and no data races.

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
| number_of_philosophers | --- | number of philosophers, and also the number of forks |
| time_to_die | ms | if a philosopher does not start eating within this time since the start of their last meal (or the start of the simulation), they die |
| time_to_eat | ms | time a philosopher spends eating, holding both forks |
| time_to_sleep | ms | time a philosopher spends sleeping |
| number_of_times_each_philosopher_must_eat | --- | optional; simulation stops when every philosopher has eaten this many times |

### Examples

```bash
# Single philosopher: takes one fork and dies (only one fork available)
./philo 1 800 200 200

# No one should ever die
./philo 5 800 200 200

# Simulation stops once every philosopher has eaten at least 7 times
./philo 5 800 200 200 7

# Tight timing, but no one should die
./philo 4 410 200 200

# One philosopher should die
./philo 4 310 200 100
```

### Make targets

- `make` / `make all` - builds `philo`
- `make clean` - removes object files
- `make fclean` - removes object files and the binary
- `make re` - fclean + all

## Resources

### References

- [Dining philosophers problem (Wikipedia)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- `man pthread_create`, `man pthread_mutex_lock`, `man gettimeofday`, `man usleep`
- [Philosophers guide (Notion)](https://suspectedoceano.notion.site/Philosophers-b1bf3c57eee6420cafa7d0900b3d3216)
- [Philosophers explained (YouTube)](https://www.youtube.com/watch?v=zOpzGHwJ3MU)

### AI usage

<!-- Please review and adjust this section so it matches your real usage. -->

- **Tool used:** Claude (Claude Code).
- **What I used it for:** as a tutor and reviewer to check the solution
  against the subject, to review the concurrency logic (fork ordering, 
  death detection, mutex protection), and to help with project hygiene
  (Makefile source list, splitting files to comply with the Norm, and 
  writing this README).