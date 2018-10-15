FROM debian:stretch-20180831

#update
RUN apt update --fix-missing

#system deps
RUN apt install -y openssh-server python2.7 make gcc

#hardening
RUN chmod o-x /usr/bin/wall
RUN chmod o-rx /var/log /run/*
RUN sed -i 's/664/660/g' /var/lib/dpkg/info/base-files.postinst

#date
RUN ln -fs /usr/share/zoneinfo/Europe/Paris /etc/localtime
RUN dpkg-reconfigure -f noninteractive tzdata

#hardening ssh
RUN sed -i 's/Last login: %s from %s/aaaaaaaaaaaaaaaaaaaaaa/g' /usr/sbin/sshd
RUN sed -i 's/Last login: %s/aaaaaaaaaaaaaa/g' /usr/sbin/sshd
RUN echo 'DebianBanner no' >> /etc/ssh/sshd_config

#create ctf-user
RUN useradd -r chall -m -s /bin/bash
RUN useradd -r chall-pwned
RUN echo chall:chall | chpasswd

#add chall items
ADD chall/Makefile /home/chall/
ADD chall/hello-world.py /home/chall
ADD chall/wrapper.c /home/chall
ADD chall/colors /usr/local/lib/python2.7/dist-packages/colors/
ADD flag /home/chall/

# prepare chall
RUN cd /home/chall && make
RUN rm -rf /home/chall/wrapper.c /home/chall/Makefile

#set some proper permissions
RUN chown -R root:root /home/chall
RUN chown root:chall-pwned /home/chall/wrapper
RUN chmod -R 755 /home/chall
RUN chmod g+s /home/chall/wrapper
run chown root:chall-pwned /home/chall/flag
RUN chmod 440 /home/chall/flag

# tmp folder
RUN chmod 773 /tmp

# for ssh
RUN mkdir /var/run/sshd

# expose ssh
EXPOSE 22

# debug
# ADD solve/ /tmp/solve

CMD ["/usr/sbin/sshd", "-D"]
