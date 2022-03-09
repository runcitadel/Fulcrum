FROM debian:bullseye as builder

ARG MAKEFLAGS

RUN apt update -y && \
    apt install -y openssl git build-essential pkg-config zlib1g-dev libbz2-dev libjemalloc-dev libjemalloc1 libzmq3-dev qtbase5-dev qt5-qmake qt5-default

WORKDIR /src

COPY . .

RUN qmake -makefile PREFIX=/usr FulcrumX.pro && \
    make $MAKEFLAGS install

FROM debian:bullseye-slim

RUN apt update && \
    apt install -y libqt5network5 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY --from=builder /src/FulcrumX /usr/bin/FulcrumX

VOLUME ["/data"]
ENV DATA_DIR /data

ENV SSL_CERTFILE ${DATA_DIR}/fulcrum.crt
ENV SSL_KEYFILE ${DATA_DIR}/fulcrum.key

EXPOSE 50001 50002

COPY contrib/docker/docker-entrypoint.sh /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]

CMD ["FulcrumX"]
