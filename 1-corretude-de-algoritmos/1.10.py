from time import time

def ulam_size(number):
    count = 1
    while number != 1:
        number = number // 2 if number % 2 == 0 else 3 * number + 1
        count += 1
    return count


bigger = -1
mean = 0
start_time = time()

for i in range(1, 65536):
  size = ulam_size(i)  
  mean += size  
  if size > bigger:
    bigger = size

mean /= 65535
end_time = time()
execution_time = end_time - start_time

print("Maior sequência: ", bigger)
print("Média dos tamanhos: ", mean)
print("Tempo de execução: ", execution_time)
