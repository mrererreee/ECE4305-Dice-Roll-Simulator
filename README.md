A simple dice rolling simulator that:
- Uses the SPI protocol to activate the Nexys A7 100T FPGA's internal accelerometer
- Imitates a dice roll by the user physically shaking the FPGA (gathering input from the accelerometer)
- With internal game logic, based on shake, produces a randomly generated number that must match another RNG number that is produced with the start condition
- Uses VGA to display text and a moving cursor sprite, alongside game graphics (pictures of die corresponding to the generated number from the shake of the user)
- Ultimately: SHAKE TO (until) WIN!


Note: Basis of all **HDL** given for this complete system was provided by **CPP ECE Professor Anas Salah Eddin**. (will be left like this until I can find the VGA files that I changed to run the graphics on my monitor)
- function **ps2_check** to incorporate PS2 mouse movement with movement of the mouse cursor sprite was provided by classmates **Elizabeth Woo** and **Vy Vo**.
- also not entirely optimized (in terms of application code) 
