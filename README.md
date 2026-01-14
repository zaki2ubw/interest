# interest

## Experiment
### 00.Know about docker
#### This is the results of experiments.
- splited RUN command image has more heavy size than merged RUN command image.
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
󰣇 snows ~/github/interest/docker/Phase00 (main)
❯ docker images | grep img-
WARNING: This output is designed for human readability. For machine-readable output, please use --format.
img-merge:latest   c568a4582d4d        605MB          164MB
img-split:latest   1892e598b6ec        724MB          212MB
```
