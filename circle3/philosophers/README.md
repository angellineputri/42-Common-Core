# philosophers

The classic dining philosophers problem implemented in C. N philosophers sit at a table and alternately eat, sleep, and think. Each needs two forks to eat; forks are shared with neighbours.

## Rules

- A philosopher who has not eaten within `time_to_die` milliseconds dies.
- The simulation stops when a philosopher dies, or when each philosopher has eaten `number_of_times_each_philosopher_must_eat` times (optional argument).
- Philosophers must not die if the timing is correct.

## Build

```sh
# mandatory (pthreads + mutexes)
cd philo
make

# bonus (processes + semaphores)
cd philo_bonus
make
```

## Run

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_count]

# example: 5 philosophers, die at 800ms, eat 200ms, sleep 200ms
./philo 5 800 200 200
```

## Implementation

| Version | Concurrency primitive |
|---------|-----------------------|
| `philo` (mandatory) | POSIX threads (`pthread`) + mutexes |
| `philo_bonus` | Processes (`fork`) + POSIX semaphores |
