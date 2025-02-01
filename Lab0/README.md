# Lab0

Lab0 contains two parts
- The first part is about toggling `LED0`, which is implemented with tag 
  `Lab0-ToggleLED`. 
- The second part is about using button `SW3` as input, to implement the 
  function that, everytime push the button, toggle the state of the `LED0`.
- Implemented with GPIO for `SW3` with pull-up mode, so everytime you 
  push `SW3`, the GPIO reads `0`.
- Implemented with tag `Lab0-ButtonInput`

## Practice for Lab0

### Problem 1

The resistor value for GPIO with pull-up and pull-down is $55k\Omega$, 
mentioned in `stm32g474ve.pdf` (datasheet of STM32G474VE, DS12288 Rev 6) at 
page 128, in table 54 which is about I/O static characteristics. The value 
is mentioned in term $R_{PU}$ and $R_{PD}$.

### Problem 2

