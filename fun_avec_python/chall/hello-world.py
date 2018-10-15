#!/usr/bin/python2.7

from colors import colors

def main():
    print('This is an advanced hello-world')
    print('The world is more joyful with colors')
    print('So, here we are:')
    print('{}Hello-World !{}'.format(colors.bcolors.OKBLUE, colors.bcolors.ENDC))

if __name__ == '__main__':
    main()
