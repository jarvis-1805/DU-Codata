install.packages("lubridate") # or either from TOOLS -> Install Packages
library(caret)
str(iris)  # view dataset structure
ytrainIndex <- createDataPartition(iris$Species, p=0.80, list=FALSE)
ytrainIndex

irisTrain <- iris[ytrainIndex,]
irisTrain # contains 120 observations

irisTest  <- iris[-ytrainIndex,]
irisTest  #contains remaining 30 observations

# Train model using the Train partition
set.seed(101)

#install.packages("RWeka", dependencies = TRUE)
library(rJava)
library(RWeka)

#dtFit <- train(Species~., method="J48", data=irisTrain, trControl = trainControl(method="cv"))

dtFit <- train(Species~., irisTrain, method ="J48", trControl = trainControl(method="cv"))


dtFit
dtFit$finalModel

# Predict using the Test partition
predictions <- predict(dtFit, irisTest)
confusionMatrix(predictions, irisTest$Species)
