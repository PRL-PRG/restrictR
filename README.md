# RestrictR

Makes execution of an expression strict by forcing promises at creation.

## Installation

``` bash
git clone git@github.com:PRL-PRG/restrictR.git
R CMD INSTALL ../restrictR
```

## Example execution

``` R
library(restrictr)
f <- function(x) { write('f', stderr()); x }
f(f({write('1', stderr()); 1}))
run_as_strict(f(f({write('1', stderr()); 1})))
```