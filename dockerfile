FROM mcr.microsoft.com/devcontainers/cpp:1-bookworm


RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    build-essential \
    cmake \
    git