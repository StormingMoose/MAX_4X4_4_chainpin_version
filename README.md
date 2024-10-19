# MAX_4X4_4_chainpin_version
MAX_4X4_4_chainpin_version uses an adapted Meccanoid library to control the Meccano M.A.X. motors configured for mecanum wheels.

Websockes are used since Http is too random in sending commands accurately and in a timely manner.  

Tried to break down the modules better but some of the techniques are elusive.


This is as far as I got to date, the wheels are not controlled accurately.  The motors seem to operate on their own timelines or something.

I left some serial prints so one can see the motor control issues.  mb stands for motor byte and with a 4 pin system the motors are all 0. 
When running the serial print line should print once for each motor that gets a message to go.  when going forward it should be all 4 every time, 
but sometimes only 3 or two lines get printed, corresponding to what you will see with the motors.

Hopefully someone can tune this up a bit.

For reasons unknown to me, the performance was much better using microsecond delays instead of the regular delay command.

