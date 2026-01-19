# Phase01: Focus on the Workspace.
## Purpose
- Understand the role of the working directory defined by WORKDIR in Docker images.
- Understand the difference in initial behavior between image built with "/" and image built with "/workspace".

## Prediction
- By default, Docker starts in the "/" directory.
- From the root directory, a user can access any location, but must manually use `cd` commands to reach the workspace.
- If a developer specifies WORKDIR in a Dockerfile, the user starts in the workspace without any manual operation.

## Result
- In short, we can reach the workspace directly by specifying WORKDIR in a Dockerfile.

### Target file
```bash
❯ cat Dockerfile.workdir
FROM ubuntu:latest

RUN apt-get update && \
apt-get install -y \
vim gcc gdb valgrind && \
rm -rf /var/lib/apt/lists/*

WORKDIR /lab
CMD ["bash"]
```
### Execution result
```bash
󰣇 snows ~/github/interest/docker/Phase01 (main)
❯ docker build -f Dockerfile.workdir -t test-env-wd .
[+] Building 1.9s (7/7) FINISHED                                                   docker:desktop-linux
 => [internal] load build definition from Dockerfile.workdir                                       0.0s
 => => transferring dockerfile: 193B                                                               0.0s
 => [internal] load metadata for docker.io/library/ubuntu:latest                                   1.8s
 => [internal] load .dockerignore                                                                  0.0s
 => => transferring context: 2B                                                                    0.0s
 => [1/3] FROM docker.io/library/ubuntu:latest@sha256:7a398144c5a2fa7dbd9362e460779dc6659bd9b19df  0.0s
 => => resolve docker.io/library/ubuntu:latest@sha256:7a398144c5a2fa7dbd9362e460779dc6659bd9b19df  0.0s
 => CACHED [2/3] RUN apt-get update && apt-get install -y vim gcc gdb valgrind && rm -rf /var/lib  0.0s
 => CACHED [3/3] WORKDIR /lab                                                                      0.0s
 => exporting to image                                                                             0.0s
 => => exporting layers                                                                            0.0s
 => => exporting manifest sha256:ba9778919621f809b781ec1a5551b21ee92366c47158cda84b9108ba6021f365  0.0s
 => => exporting config sha256:c1b46d7ccc608a363de4a65c56a5f9a1fa8a9d9d2657795930ac07a15b1be452    0.0s
 => => exporting attestation manifest sha256:d839b916d7143a98545bd9e62015168f94316c0702198b8087d4  0.0s
 => => exporting manifest list sha256:e9383d4e72cd32945f98ba27b217abd1d68983b471276f5ff3684bd234b  0.0s
 => => naming to docker.io/library/test-env-wd:latest                                              0.0s
 => => unpacking to docker.io/library/test-env-wd:latest                                           0.0s
󰣇 snows ~/github/interest/docker/Phase01 (main)
❯ docker run -it test-env-wd
root@10d08bda60e9:/lab# pwd
/lab
root@10d08bda60e9:/lab#
exit
```
### Problems
- I lost the logs of failed experiments, so I describe the problems here.
1. If there is no file named "Dockerfile" in the directory, the "docker build" command cannot find Dockerfiles with custom names like "Dockerfile.test".
2. Some tools cannot install by using "apt-get install **". I tried to install "Norminette" but it failed.

### Considerations
- By default, the "docker build" command cannot find a Dockerfile with a custom name like "Dockerfile.test".
- I think this problem can be solved by specifying the filename.
- Some packages cannot find in apt repositories, so we need to take another aproach to solve this problem.

## Conclusion
Through this experiment, I discovered the benefits of specifying WORKDIR, learned two tips about Docker commands, and identified another problem to address in future experiments.

### The merit of specifying WORKDIR
- If a developer specifies WORKDIR, they can set the best default directory for their environment.
- This is a strong merit for developers, because they can guide user behavior when using their environments.
- Therefore, specifying WORKDIR can be considered a de facto standard when using Docker.

### Tips for Docker commands
- If there is no file named "Dockerfile" in the current directory, we need to create one or specify a Dockerfilename using the `-f` option, such as "Dockerfile.test"

NG: Read the default Dockerfile
```bash
docker build -t IMAGE DIR
```

OK: Read a specified Dockerfile using the `-f` option.
```bash
docker build -f FILENAME -t IMAGE DIR
```
- Some Docker commands behave like two-stage commands.
- For example, `docker build` and `docker run`.
- I have not checked all Docker commands, so this observation is based on my own experience.

Docker command format
```bash
docker run [OPTIONS] IMAGE [COMMAND] [ARG...]
```
Linux commands format
```bash
cmd [options] [args]
```
- I think this structure can be explain by the following example.
```bash
Linux : Docker

cmd == docker build/docker run/docker */...
option == [OPTIONS]
args == IMAGE [COMMAND] [ARG...]
```
- Based on this example, we can say the arguments of `docker run` are interpreted as commands executed inside the countainer created from the IMAGE.

### Another problem
- In this experiment, I tried to install "Norminette" by using "apt-get install" in RUN institution.
- However ,the installation failed. Because, there is no reference of "Norminette" in apt repos.
- As a result, I need another approach to install applications like "Norminette".
