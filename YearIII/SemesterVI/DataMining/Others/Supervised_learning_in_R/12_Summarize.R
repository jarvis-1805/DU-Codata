library(caret)

control <- trainControl(method="cv", number=10)
metric <- "Accuracy"

validation_index <- createDataPartition(iris$Species, p=0.80, list=FALSE)
# select 20% of the data for validation
validation <- iris[-validation_index,]
# use the remaining 80% of data to training and testing the models
dataset <- iris[validation_index,]


#Neural network
set.seed(7)
fit.nnet <- train(Species~., data=dataset, method="nnet", metric=metric, trControl=control)
# J48
set.seed(7)
fit.dt <- train(Species~., data=dataset, method="J48", metric=metric, trControl=control)
# kNN
set.seed(7)
fit.knn <- train(Species~., data=dataset, method="knn", metric=metric, trControl=control)
# NB
set.seed(7)
fit.nb <- train(Species~., data=dataset, method="nb", metric=metric, trControl=control)


# summarize accuracy of models
results <- resamples(list(nnet=fit.nnet, dt=fit.dt, knn=fit.knn, nb = fit.nb))
summary(results)


# compare accuracy of models
dotplot(results)

print(fit.nb)

# estimate skill of LDA on the validation dataset
predictions <- predict(fit.nb, validation)
confusionMatrix(predictions, validation$Species)
