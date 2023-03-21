# First Program
string <-"Hello Duniya!"
print(string)

student <- data.frame(
  stud_id = c (1:10),
  stud_name = c("Nikhil","Om","Shruti","Roy","Joy","Priya","Ravi","Ram","Sham","Riya"),
  marks = c("89","91","59","85","87","82","93","80","90","93"),
  gender = c("Male","Male","Female","Male","Male","Female","Male","Male","Male","Female")
)
# Print data frame.
print(student)
str(student)
print(summary(student))
print(typeof(student))

a <- c(readline(prompt = "Enter First Number"))
b <- c(readline(prompt = "Enter Second Number"))
d <- as.integer
c <- a+b
print(c)