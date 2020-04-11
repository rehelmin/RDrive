#
# J-LINK GDB SERVER initialization
#
file /home/rehelmin/develop/ODriveV2/build/odrivev2.elf

# This connects to a GDB Server listening
# for commands on localhost at tcp port 2331
target remote localhost:2331

# Set gdb server to little endian
monitor endian little
# Reset the chip to get to a known state.
monitor reset
 #
# CPU core initialization (to be done by user)
#
# Set the processor mode
monitor reg cpsr = 0xd3
# Set auto JTAG speed
monitor speed auto
# Setup GDB FOR FASTER DOWNLOADS
set remote memory-write-packet-size 1024
set remote memory-write-packet-size fixed
# Load the program executable called "image.elf"
load build/odrivev2.elf
break main
