FROM ubuntu:latest

#Installation des packages pour le développement c++
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    libboost-all-dev \
    build-essential \
    clang \
    cmake \
    gdb \
    wget \
    git

# Mets a jour les certificats pour git
RUN apt install -y --reinstall ca-certificates