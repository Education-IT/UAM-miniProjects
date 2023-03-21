# ZAD 2 --------------------------------
cat("\014")
x <- rep(c(TRUE,FALSE,TRUE,FALSE), times = c(3,4,2,5))
x
x <- as.numeric(x)
x
rm(x)


# ZAD 3 --------------------------------
cat("\014")
x <- c(c(1:20), rep(0,10), seq(2,40,by=2))
x <- c(x, x[length(x):1])
x
sprintf("X length: %d" , length(x))
rm(x)


# ZAD 4 --------------------------------
cat("\014")
x <- letters[c(5,10,15,20,25)]
x
rm(x)


# ZAD 5 -------------------------------- 
cat("\014")
x <- 1:1000
for (number in x){
  if(number %% 2 == 0){
    x[number] = 1/number
  }
}
head(x)
rm(x)


# ZAD 6 -------------------------------- 
cat("\014")
x <- c(6,3,4,5,2,3)
y <- order(x,decreasing = TRUE)
z <- 1:6 
for(i in 1:6){
  z[i] <- x[[y[i]]]
}
z
rm(x,y,z)



# ZAD 7 -------------------------------- 
cat("\014")
x <- c(-1.876,-1.123,-0.123,0,0.123,1.123,1.876)
y <- sign(x)
y
z <- round(x,2)
z
a <- floor(z)
a
rm(x,y,z,a)



# ZAD 8 -------------------------------- 
cat("\014")
SQRT_start <- Sys.time()
for(i in 1:100){
  sqrt(i)
}
SQRT_stop <- Sys.time()

po_start <- Sys.time()
for(i in 1:100){
  i^(1/2)
}
po_stop <- Sys.time()

SQRT_stop - SQRT_start
po_stop - po_start

rm(SQRT_stop,SQRT_start,po_stop,po_start)



# ZAD 9 -------------------------------- 
install.packages("schoolmath")
library(schoolmath)
cat("\014")
ramka <- data.frame(dane = primlist[1:1000])
length(ramka[ramka$dane <= 1000,])
length(ramka[ramka$dane > 100 & ramka$dane < 500,])
rm(ramka)



# ZAD 10 -------------------------------- 
cat("\014")
paste0(rep(c("a","b"),c(3,3)) , 1:3 )


# ZAD 11 -------------------------------- 
cat("\014")
paste0(1:30,"." ,c("X","Y","Z"))


# ZAD 12 -------------------------------- 
install.packages("carData")
library(carData)
install.packages("car")
library(car)
cat("\014")
x <- sample(c("a","b","c","d","e"),100,replace = TRUE)
x
recode(x,"'a'~'b' -> 1 // 'c'~'d' -> 2 // 'e' -> 3" ,to.value="->", interval="~", separator="//")
rm(x)



# ZAD 13 -------------------------------- 
cat("\014")
moja_lista <- list(c("Krystian","Osinski"),3.14,function(x)return(x^2),seq(0.02 , 1 , by=0.02))
moja_lista
x <- moja_lista[-c(1,3)]
x
x <- lapply(x, gamma)
x
rm(moja_lista,x)

# ZAD 14 --------------------------------
cat("\014")
kwadrat <- function(x) return(x^2)
x <- sapply(1:100, kwadrat)
x
n <- 0:9
m <- rep(0,10)
  for(number in x){
    mod <- number %% 10
  m[mod+1] <- m[mod+1] + 1  
  }
ramka <- data.frame(n,m)
ramka
rm(ramka,m,n,x,kwadrat,mod,number)



# ZAD 15 --------------------------------
tab <- function(x,y){
  return(paste(x," * ",y," = ", x*y))
  
}

cat("\014")
x <- 1:5
y <- 1:5
outer(y,x,tab)
rm(tab,x,y)


# ZAD 16 --------------------------------
cat("\014")
table <-  read.csv("dane1.csv",header = TRUE,sep = ";")
table[-seq(1,nrow(table),by=2),]
table[table$Wiek>50 & table$Wezly.chlonne == 1,]
rm(table)


# ZAD 17 --------------------------------
cat("\014")
x <- 1:5
i <- 1 
v_WHILE <-  1

while(i<=length(x)){
  v_WHILE <- v_WHILE * x[i]
  
  i <- i + 1
}
v_WHILE

v_REPEAT <- 1
i <- 1
repeat{
  v_REPEAT <- v_REPEAT * x[i]
  i <- i + 1
  if(i>length(x)) break
}
v_REPEAT


v_FOR <- 1 

for(number in x){
  v_FOR <- v_FOR * number
}
v_FOR

rm(x,i,v_FOR,v_REPEAT,v_WHILE,number)




# ZAD 18 --------------------------------
ile <- 0
for(n in 1:100){
  for(r in n:1){
    if(choose(n,r) > 10^6){
      ile <- ile + 1
    }
  }
}
ile
rm(ile,n,r)

# ZAD 19 --------------------------------
cat("\014")
x <- c(2, 6, 1, 5, 7, 3, 4)
z <- c(1,2)
fun <- function(x){
  if(length(x)<3){
    stop("za krótki argument!")
  }
  x <- sort(x)
  return(c(x[1:3],x[length(x)-2]:x[length(x)]))
}
y <- fun(x)
y
y <- fun(z)
rm(x,y,z,fun)

