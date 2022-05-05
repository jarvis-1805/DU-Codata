library(caret)

control <- trainControl(method="cv", number=10)
control

metric <- "Accuracy"
metric

validation_index <- createDataPartition(iris$Species, p=0.80, list=FALSE)
validation_index  #120 observations

# select 20% of the data for validation
validation <- iris[-validation_index,]  
validation  # 30 observations

# use the remaining 80% of data to training and testing the models
dataset <- iris[validation_index,]
View(dataset)   #training IRIS dataset

#Neural network
set.seed(7)
fit.nnet <- train(Species~., data=dataset, method="nnet", metric=metric, trControl=control)
fit.nnet

#J48
#install.packages("RWeka")
#library(RWeka)
#set.seed(7)
#fit.dt <- train(Species~., data=dataset, method="J48", metric=metric, trControl=control)

# kNN
set.seed(7)
fit.knn <- train(Species~., data=dataset, method="knn", metric=metric, trControl=control)
fit.knn

# NB
set.seed(7)
fit.nb <- train(Species~., data=dataset, method="nb", metric=metric, trControl=control)
fit.nb

# summarize accuracy of models
results <- resamples(list(nnet=fit.nnet, knn=fit.knn, nb = fit.nb))

#results <- resamples(list(nnet=fit.nnet, dt=fit.dt, knn=fit.knn, nb = fit.nb))  # not working 
#because of DT


summary(results)


# compare accuracy of models
dotplot(results)

print(fit.nb)

# estimate skill of LDA on the validation dataset
predictions <- predict(fit.nb, validation)
predictions

confusionMatrix(predictions, validation$Species)
