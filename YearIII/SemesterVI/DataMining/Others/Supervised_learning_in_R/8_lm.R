library(caret)

### Installing caret package in RStudio by default installs all the dependencies

### all details about package caret can be found here: http://topepo.github.io/caret/index.html
### if any script requires installation of additional packages, please install it.

## multiple variable
regressControl  <- trainControl(method="repeatedcv",
                                number = 4,
                                repeats = 5
) 

regress <- train(mpg ~ .,
                 data = mtcars,
                 method  = "lm",
                 trControl = regressControl, 
                 tuneGrid  = expand.grid(intercept = FALSE))
regress

summary(regress)

## single variable

regress2 <- train(mpg ~ hp,
                 data = mtcars,
                 method  = "lm",
                 trControl = regressControl, 
                 tuneGrid  = expand.grid(intercept = FALSE))
regress2

qplot(mpg, hp, data = mtcars, main = "Relationship between mpg and hp") +
  stat_smooth(method="lm", col="red")
