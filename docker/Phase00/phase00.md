# Learning Docker
## Experiment00 Know about docker

## Purpose
To compare Docker image sizes between split RUN instructions and merged RUN instructions.

## Result
The image built with split RUN instructions is larger than the image built with merged RUN instructions.

### Target images

```bash
󰣇 snows ~/github/interest/docker/Phase00 (main)
❯ cat Dockerfile.split Dockerfile.merge
FROM ubuntu:22.04

RUN echo "===THIS IS SPLIT CASE==\n"
RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y gcc
RUN apt-get install -y gdb
RUN apt-get install -y valgrind
RUN rm -rf /var/lib/apt/lists/*
CMD ["bash"]
FROM ubuntu:22.04

RUN echo "===THIS IS MERGE CASE===\n"
RUN apt-get update && \
apt-get install -y \
vim gcc gdb valgrind && \
rm -rf /var/lib/apt/lists/*
CMD ["bash"]
```
### Differences

```bash
󰣇 snows ~/github/interest/docker/Phase00 (main)
❯ docker images | grep img-
WARNING: This output is designed for human readability. For machine-readable output, please use --format.
img-merge:latest   c568a4582d4d        605MB          164MB
img-split:latest   1892e598b6ec        724MB          212MB
```

## Conclusion
- The image built with merged "RUN" instructions is smaller than the image built with split "RUN" instructions.
- This is because each RUN instruction creates an immutable layer in a Docker image.
- Each immutable layer preserves its data, and it cannot be removed by later layers.
- Even if files are deleted, that data added in previous layers remains.
- Therefore, cleanup commands must be executed in the same "RUN" instructions using '&&'.

## KEYWORD
- A RUN instruction behaves like an immutable history layer in a Docker image.
