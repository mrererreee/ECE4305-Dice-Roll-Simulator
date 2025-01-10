A simple dice rolling simulator that:
- Uses the SPI protocol to activate the Nexys A7 100T FPGA's internal accelerometer
- Imitates a dice roll with a user's shake of the FPGA to gather input from the accelerometer
- With internal game logic, based on shake, produces a randomly generated number that must match another RNG number that is produced with the start condition
- Uses VGA to display text and a moving cursor sprite, alongside game graphics (pictures of die corresponding to the generated number from the shake of the user)
- Ultimately: SHAKE TO (until) WIN!


Note: Basis of all HDL given for this complete system was provided by CPP ECE Professor Anas Salah Eddin. (will be left like this until I can find the VGA files that I changed to run the graphics on my monitor)
- also not entirely optimized (in terms of application code) 
