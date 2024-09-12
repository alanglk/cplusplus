FROM alpine:latest

# install build dependencies to build and debug 
RUN apk add --update alpine-sdk
RUN apt update && apt install -y g++ build-essential make cmake gdb gdbserver rsync zip openssh-server git 

# install application dependencies
# RUN apt-get install -y libopenblas-dev liblapack-dev python3-dev \ 
#     libncurses5-dev libncursesw5-dev libasio-dev libboost-all-dev

# Configurar SSH for communication with Visual Studio 
RUN mkdir -p /var/run/sshd
RUN echo 'root:root' | chpasswd \
    && sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config \
    && sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

# Crear el usuario nonroot con los mismos permisos que el host y perteneciente a sudoers
RUN apt update && \
    apt install -y sudo && \
    addgroup --gid $GID nonroot && \
    adduser --uid $UID --gid $GID --disabled-password --gecos "" nonroot && \
    echo 'nonroot ALL=(ALL) NOPASSWD: ALL' >> /etc/sudoers

# Establecemos el nuevo usuario y el directorio de trabajo
USER nonroot
WORKDIR /home/nonroot/

CMD ["/usr/sbin/sshd", "-D"]
EXPOSE 22