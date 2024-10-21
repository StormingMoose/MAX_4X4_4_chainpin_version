# MAX_4X4_4_chainpin_version
MAX_4X4_4_chainpin_version uses an adapted Meccanoid library to control the Meccano M.A.X. motors configured for mecanum wheels.

Websockes are used since Http is too random in sending commands accurately and in a timely manner.  

Tried to break down the modules better but some of the techniques are elusive.


This is as far as I got to date, the wheels are not controlled accurately.  The motors seem to operate on their own timelines or something.

I left some serial prints so one can see the motor control issues.  mb stands for motor byte and with a 4 pin system the motors are all 0. 
When running the serial print line should print once for each motor that gets a message to go.  when going forward it should be all 4 every time, 
but sometimes only 3 or two lines get printed, corresponding to what you will see with the motors.

Hopefully we can tune this up a bit.

I posted a serial monitor example of the error problem, the front wheels are 62 and 46, the rear wheels are 63 and 47.

There should be four lines of output when going North, the first loop shown is fine but then only 2 wheels are willing to play, until 4 wheels again for three lops.  I wish it was a consistent error that would point to a hardware issue, but nothing is pointing in that direction other than one grinds a bit.
