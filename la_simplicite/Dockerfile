FROM debian:stretch-20180831

#update
RUN apt update --fix-missing

RUN apt install -y apache2 php7.0

#hardening
RUN chmod o-x /usr/bin/wall
RUN chmod o-rx /var/log /run/*
RUN sed -i 's/664/660/g' /var/lib/dpkg/info/base-files.postinst

#date
RUN ln -fs /usr/share/zoneinfo/Europe/Paris /etc/localtime
RUN dpkg-reconfigure -f noninteractive tzdata

RUN echo 'ServerTokens ProductOnly' >> /etc/apache2/apache2.conf
RUN echo 'ServerSignature Off' >> /etc/apache2/apache2.conf

RUN chmod 773 /tmp

WORKDIR /var/www/html

VOLUME ["/var/www/html"]

ENV APACHE_RUN_USER www-data
ENV APACHE_RUN_GROUP www-data
ENV APACHE_LOG_DIR /var/log/apache2
ENV APACHE_PID_FILE /var/run/apache2.pid
ENV APACHE_RUN_DIR /var/run/apache2
ENV APACHE_LOCK_DIR /var/lock/apache2

RUN mkdir -p $APACHE_RUN_DIR $APACHE_LOCK_DIR $APACHE_LOG_DIR

EXPOSE 80

ENTRYPOINT [ "/usr/sbin/apache2" ]
CMD ["-D", "FOREGROUND"]
