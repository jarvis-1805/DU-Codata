#-----------Vectors--------------------------#

8.5:4.5 #sequence of numbers from 8.5 down to 4.5
c(1, 1:3, c(5, 8), 13) #values concatenated into single vector

vector("numeric", 5)

vector("complex", 5)

vector("logical", 5)

vector("character", 5)

vector("list", 5)

numeric(5)
complex(5)
logical(5)
character(5)

#---------------Lengths-------------------------------------------------#

length(1:5)
length(c(TRUE, FALSE, NA))
sn <- c("Sheena", "leads", "Sheila", "needs")
length(sn)
nchar(sn)

pp <- c("Peter", "Piper", "picked", "a", "peck", "of", "pickled","peppers")
for(i in 1:length(pp)) print(pp[i])

i <- 1
while (i <= length(pp)) {
  print (pp[i])
  i <- i + 1
}
        
#----------------Names------------------------------------------------#

c(apple = 1, banana = 2, "kiwi fruit" = 3, 4)

x <- 1:4;x
names(x) <- c("apple", "bananas", "kiwi fruit", "")
x
names(x)
names(1:4)


#-----------Indexing Vectors-----------------------------------------------------#
x <- (1:5) ^ 2
x
x[2:4]

#Follwoing three indexing methods return the same values
x[c(1, 3, 5)]
x[c(-2, -4)]
x[c(TRUE, FALSE, TRUE, FALSE, TRUE)]

#After naming each element, this method also returns the same values:
names(x) <- c("one", "four", "nine", "sixteen", "twenty five")
x[c("one", "nine", "twenty five")]

#Mixing positive and negative values is not allowed, and will throw an error:
  x[c(1, -1)] #This doesn't make sense! Error: only 0's may be mixed with negative subscripts

#If you use positive numbers or logical values as the index, then missing indices correspond
#to missing values in the result:
x[c(1, NA, 5)]

x[c(TRUE, FALSE, NA, FALSE, TRUE)]


#Out of range indices, beyond the length of the vector, don't cause an error, but instead
#return the missing value NA
x[6]


#Noninteger indices are silently rounded toward zero.
x[1.9] #1.9 rounded to 1
x[-1.9] #-1.9 rounded to -1

#which function returns the locations where a logical vector is TRUE
which(x > 10)
which.min(x)
which.max(x)


#------Vector Recycling and Repetition----------------------------------------------------------#
#add a single number to a vector, then that number is added to each element of the vector
1:5 + 1

1 + 1:5

#When adding two vectors together, R will recycle elements in the shorter vector to match the longer one:
1:5 + 1:15

#If the length of the longer vector isn't a multiple of the length of the shorter one, a warning will be given:
1:5 + 1:7

rep(1:5, 3)

rep(1:5, each = 3)

rep(1:5, times = 1:5)

rep(1:5, length.out = 7)

rep.int(1:5, 3) #the same as rep(1:5, 3)

rep_len(1:5, 13)

#------------------------------------------------------------------------------------#
#--------------------Creating Arrays and Matrices------------------------------------#
#create an array: pass vector of values and  vector of dimensions. 
#Optionally, you can also provide names for each dimension

(three_d_array <- array(
  1:24,
  dim = c(4, 3, 2),
  dimnames = list(
    c("one", "two", "three", "four"),
    c("ein", "zwei", "drei"),
    c("un", "deux")
  )
))

#Ceating matrices: specify the number of rows or the number of columns

#matrix could also be created using the array function
(two_d_array <- array(
  1:12,
  dim = c(4, 3),
  dimnames = list(
    c("one", "two", "three", "four"),
    c("ein", "zwei", "drei")
  )
))

(a_matrix <- array(
  1:12,
  dim = c(4, 3),
  dimnames = list(
    c("one", "two", "three", "four"),
    c("ein", "zwei", "drei")
  )
))

identical(two_d_array, a_matrix)
class(two_d_array)

#-----Rows, Columns, and Dimensions-----------------------------------------------------------#

dim(three_d_array)  ## [1] 4 3 2
dim(a_matrix)       ## [1] 4 3

nrow(a_matrix)      ## [1] 4
ncol(a_matrix)      ## [1] 3

length(three_d_array)    ## [1] 24   product of each of the dimensions
length(a_matrix)         ## [1] 12

#reshape a matrix; dimension names are stripped
a_matrix
dim(a_matrix) <- c(6, 2)
a_matrix

nrow(a_matrix)
NROW(a_matrix)

identical(nrow(a_matrix), NROW(a_matrix))
identical(ncol(a_matrix), NCOL(a_matrix))

recaman <- c(0, 1, 3, 6, 2, 7, 13, 20)
recaman

nrow(recaman)       ## NULL
NROW(recaman)       ## [1] 8

ncol(recaman)       ## NULL
NCOL(recaman)       ## [1] 1

dim(recaman)

#-----Row, Column, and Dimension Names-----------------------------------------------------------#
(a_matrix <- matrix(
  1:12,
  nrow = 4, #ncol = 3 works the same
  dimnames = list(
    c("one", "two", "three", "four"),
    c("ein", "zwei", "drei")
  )
))

rownames(a_matrix)               ## [1] "one" "two" "three" "four"
colnames(a_matrix)               ## [1] "ein" "zwei" "drei"
dimnames(a_matrix)

rownames(three_d_array)          ## [1] "one" "two" "three" "four"
colnames(three_d_array)          ## [1] "ein" "zwei" "drei"
dimnames(three_d_array)

#--------Indexing Arrays--------------------------------------------------------#
a_matrix
a_matrix[1, c("zwei", "drei")] #elements in 1st row, 2nd and 3rd columns

#To include all of a dimension, leave the corresponding index blank
seq.int(2,24,2)

a_matrix[1, ] #all of the first row
a_matrix[, c("zwei", "drei")] #all of the second and third columns

#----Combining Matrices------------------------------------------------------------#
(another_matrix <- matrix(
  seq.int(2, 24, 2),
  nrow = 4,
  dimnames = list(
    c("five", "six", "seven", "eight"),
    c("vier", "funf", "sechs")
  )
))

a_matrix
another_matrix
c(a_matrix, another_matrix)

cbind(a_matrix, another_matrix)
rbind(a_matrix, another_matrix)

#-----Array Arithmetic-----------------------------------------------------------#
a_matrix + another_matrix
a_matrix * another_matrix

#adding nonconformable matrices throws an error

matrix(1:12, nrow=12)
matrix(1:12, nrow=1)

(another_matrix <- matrix(1:12, nrow = 2))

a_matrix
t(a_matrix)       #transposes matrix

a_matrix %*% t(a_matrix) #inner multiplication

1:3
4:6
1:3 %o% 4:6 #outer multiplication

outer(1:3, 4:6) #same

#Matrix inversion
(m <- matrix(c(1, 0, 1, 5, -3, 1, 2, 4, 7), nrow = 3))
m ^ -1     #does not give inverse; works element-wise on matrices

m
solve(m)
(inverse_of_m <- solve(m))
m %*% inverse_of_m


#-----------Lists and Data Frames-----------------------------------------------------#
#----Creating Lists------------------------------------------------------------#
month.abb
asin

(a_list <- list(
  c(1, 1, 2, 5, 14, 42), 
  month.abb,
  matrix(c(3, -8, 1, -3), nrow = 2),
  asin
))

#can name elements during construction, or afterward using the names function

names(a_list) <- c("catalan", "months", "involutary", "arcsin")
a_list

(the_same_list <- list(
  catalan = c(1, 1, 2, 5, 14, 42),
  months = month.abb,
  involutary = matrix(c(3, -8, 1, -3), nrow = 2),
  arcsin = asin
))

#possible for elements of lists to be lists themselves
(main_list <- list(
  middle_list = list(
    element_in_middle_list = diag(3),
    inner_list = list(
      element_in_inner_list = pi ^ 1:4,
      another_element_in_inner_list = "a"
    )
  ),
  element_in_main_list = log10(1:10)
))

#----------------------------------------------------------------#
#Atomic and Recursive Variables

is.atomic(list())             ## [1] FALSE
is.recursive(list())          ## [1] TRUE
is.atomic(numeric())          ## [1] TRUE
is.recursive(numeric())       ## [1] FALSE
   
#----------------------------------------------------------------#
#List Dimensions and Arithmetic
#List's length is the number of top-level elements that it contains

a_list
length(a_list)               ## [1] 4
length(main_list) #doesn't include the lengths of nested lists  ## [1] 2

#lists don't have dimensions; dim function returns NULL
dim(a_list)

#nrow, NROW,ncol, NCOL  work on lists in the same way as on vectors
nrow(a_list)          ## NULL
ncol(a_list)          ## NULL
NROW(a_list)          ## [1] 4
NCOL(a_list)          ## [1] 1

#----------------------------------------------------------------#
#Indexing Lists

l <- list(
  first = 1,
  second = 2,
  third = list(
    alpha = 3.1,
    beta = 3.2
  )
)

l  #print l

#all following give the same result
l[1:2]
l[-3]
l[c("first", "second")]
l[c(TRUE, TRUE, FALSE)]

#Result of indexing operations is another list
l
l[1]

#Instead, to access the contents of the list elements Use [[]] or single string naming that element
l[[1]]

l[["first"]]

l$first    #Autocomplete using tab
l$f #partial matching interprets "f" as "first"


#-------#Converting Between Vectors and Lists#-----------------------------------#

busy_beaver <- c(1, 6, 21, 107) 
busy_beaver
as.list(busy_beaver)

as.numeric(list(1, 6, 21, 107))   #convert list to vector if each element of list contains a scalar value

(prime_factors <- list(
  two = 2,
  three = 3,
  four = c(2, 2),
  five = 5,
  six = c(2, 3),
  seven = 7,
  eight = c(2, 2, 2),
  nine = c(3, 3),
  ten = c(2, 5)
))

unlist(prime_factors)  #to convert list with nonrectangular shape

#-------Combining Lists-----------------------------------#
list(a = 1, b = 2)
list(3)
c(list(a = 1, b = 2), list(3))   #concatenate lists
c(list(a = 1, b = 2), 3)         #concatenate list and vector

#-------NULL ----------------------------------------------#
#Some months have no bank holidays, so we use NULL to represent this absence

(uk_bank_holidays_2018 <- list(
  Jan = "New Year's Day",
  Feb = NULL,
  Mar = "Good Friday",
  Apr = "Easter Monday",
  May = c("Early May Bank Holiday", "Spring Bank Holiday"),
  Jun = NULL,
  Jul = NULL,
  Aug = "Summer Bank Holiday",
  Sep = NULL,
  Oct = NULL,
  Nov = NULL,
  Dec = c("Christmas Day", "Boxing Day")
))

uk_bank_holidays_2018$Jan
uk_bank_holidays_2018$Feb

uk_bank_holidays_2018$Jan <- NULL    #NULL can be used to remove elements of a list
uk_bank_holidays_2018$Feb <- NULL
uk_bank_holidays_2018

uk_bank_holidays_2018["Aug"] <- list(NULL)   #set an existing element to be NULL
uk_bank_holidays_201z = runif(5) > 0.5

length(NULL)
length(NA)


#----------------------Data Frames---------------------------#
#---------------Creating Data Frames-------------------------#

(a_data_frame <- data.frame(
  x = letters[1:5],
  y = rnorm(5),
  z = runif(5) > 0.5
))

class(a_data_frame)

#rows have been automatically numbered from one to five
# if input vectors have names, row names taken from the first such vector

y <- rnorm(5)
y
names(y) <- month.name[1:5]
y

data.frame(
  x = letters[1:5],
  y = y,
  z = runif(5) > 0.5
)

#behavior can be overridden by passing the argument row.names = NULL
data.frame(
  x = letters[1:5],
  y = y,
  z = runif(5) > 0.5,
  row.names = NULL
)

#can provide your own row names by passing a vector to row.names (this Vector converted to character)
#colnames and dimnames can be used to get or set the column and dimension names
#nrow,ncol, and dim also work in exactly the same way as they do in matrices

data.frame(
  x = letters[1:5],
  y = y,
  z = runif(5) > 0.5,
  row.names = c("Jackie", "Tito", "Jermaine", "Marlon", "Michael")
)

#row names can be retrieved or changed using rownames (or row.names)
a_data_frame
rownames(a_data_frame)
colnames(a_data_frame)
dimnames(a_data_frame)
nrow(a_data_frame)
ncol(a_data_frame)
dim(a_data_frame)

#two quirks that you need to be aware of:
#length returns the same value as ncol, not the total number of elements in the data frame
#names returns the same value as colnames
length(a_data_frame)
names(a_data_frame)

#possible to create a data frame by passing different lengths of vectors, as long as the
#lengths allow the shorter ones to be recycled an exact number of times
data.frame( #lengths 1, 2, and 4 are OK
  x = 1, #recycled 4 times
  y = 2:3, #recycled twice
  z = 4:7 #the longest input; no recycling
)

#If the lengths are not compatible, then an error will be thrown:
data.frame( #lengths 1, 2, and 3 cause an error
  x = 1, #lowest common multiple is 6, which is more than 3
  y = 2:3,
  z = 4:6
)

#when creating data frames is that by default the column names are checked to be
#unique valid variable names.
#This feature can be turned off by passing check.names = FALSE to data.frame
#However, having nonstandard column names is a bad idea. 
#Duplicating column names is even worse, since it can lead to 
#hard-to-find bugs once you start taking subsets

data.frame(
  "A column" = letters[1:5],
  "!@#$%^&*()" = rnorm(5),
  "..." = runif(5) > 0.5,
  check.names = FALSE
)

data.frame(
  "A column" = letters[1:5],
  "!@#$%^&*()" = rnorm(5),
  "..." = runif(5) > 0.5,
  check.names = TRUE
)

#----------------Indexing Data Frames------------------------------------#
a_data_frame
#same results
a_data_frame[2:3, -3]
a_data_frame[2:3, c(1,2)]
a_data_frame[2:3, (1,2)]a_data_frame[c(FALSE, TRUE, TRUE, FALSE, FALSE), c("x", "y")]

#If more than one column is selected, the resultant subset is also a data frame. 
#If only one column is selected, the result will be simplified to be a vector
class(a_data_frame[2:3, -3])

class(a_data_frame[2:3, 1])

#To select one column, list-style indexing 
#(double square brackets with a positive integer or name, 
#or the dollar sign operator with a name)
a_data_frame
a_data_frame$x[2:3]

a_data_frame[[1]][2:3]

a_data_frame[["x"]][2:3]

#placing conditions on columns, the syntax can get a bit clunky
a_data_frame[a_data_frame$y > 0 | a_data_frame$z, "x"]

#subset functionn takes up to three arguments: 
#a data frame to subset, a logical vector of conditions for rows to
#include, and a vector of column names to keep
subset(a_data_frame, y > 0 | z, x)

#transpose using the t function
#all columns (which become rows) are converted to the same type, and dataframe becomes a matrix
a_data_frame
t(a_data_frame)


class(t(a_data_frame))

#Data frames can also be joined together using cbind and rbind
another_data_frame <- data.frame( #same cols as a_data_frame, different order
  z = rlnorm(5), #lognormally distributed numbers
  y = sample(5), #the numbers 1 to 5, in some order
  x = letters[3:7]
)

another_data_frame

rbind(a_data_frame, another_data_frame)
cbind(a_data_frame, another_data_frame)

#If two data frames share columns, they can be merged together using the merge function
a_data_frame
another_data_frame
merge(a_data_frame, another_data_frame, by = "x")

merge(a_data_frame, another_data_frame, by = "x", all = TRUE)

#functions colSums/rowSums and colMeans/rowMeans can be used to 
#calculate the sums and means of each column/row
a_data_frame
colSums(a_data_frame[, 2:3])
colMeans(a_data_frame[, 2:3])

#-------------Functions-------------------------------------------#
#rt function, which generates random numbers from a t-distribution
rt

#function to calculate the length of the hypotenuse of a right-angled triangle
hypotenuse <- function(x, y)
{
  sqrt(x ^ 2 + y ^ 2)
}

hypotenuse <- function(x, y) sqrt(x ^ 2 + y ^ 2) #can omit braces for single line; same as before
hypotenuse(3, 4)

hypotenuse(y = 24, x = 7)   #pass named arguments to change the order that we pass the arguments

hypotenuse <- function(x = 5, y = 12)              #defaultvalues
{
  sqrt(x ^ 2 + y ^ 2)
}
hypotenuse() #equivalent to hypotenuse(5, 12)


#Passing Functions to and from Other Functions
#common example of a function that takes another function as an argument is do.call.
do.call(hypotenuse, list(x = 3, y = 4)) #same as hypotenuse(3, 4)

#most common use case for do.call is with rbind. You can use these two
#functions together to concatenate several data frames or matrices together at once
dfr1 <- data.frame(x = 1:5, y = rt(5, 1))
dfr1
dfr2 <- data.frame(x = 6:10, y = rf(5, 1, 1))
dfr2
dfr3 <- data.frame(x = 11:15, y = rbeta(5, 1, 1))
dfr3
do.call(rbind, list(dfr1, dfr2, dfr3)) #same as rbind(dfr1, dfr2, dfr3)

#can also pass functions anonymously:
x_plus_y <- function(x, y) x + y
do.call(x_plus_y, list(1:5, 5:1))

#is the same as
do.call(function(x, y) x + y, list(1:5, 5:1))

#Functions can return functions
#ecdf function returns the empirical cumulative distribution function of a vector

(emp_cum_dist_fn <- ecdf(rnorm(50)))
emp_cum_dist_fn
is.function(emp_cum_dist_fn)
plot(emp_cum_dist_fn)

#----------------------------*****---------------------------------------------------------------------------------#
#------------------Sequences----------------------------------------------#
seq.int(3, 12) #same as 3:12
seq.int(3, 12, 2)
seq.int(0.1, 0.01, -0.01)

n <- 0
1:n #not what you might expect!
## [1] 1 0
seq_len(n)
## integer(0)

pp <- c("Peter", "Piper", "picked", "a", "peck", "of", "pickled", "peppers")
seq_along(pp)
for(i in seq_along(pp)) print(pp[i])
