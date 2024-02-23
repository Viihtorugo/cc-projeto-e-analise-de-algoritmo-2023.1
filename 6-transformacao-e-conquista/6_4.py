import pulp

problem = pulp.LpProblem("Problema de Programação Linear", pulp.LpMaximize)

x = pulp.LpVariable('x', lowBound=0)  # x >= 0
y = pulp.LpVariable('y', lowBound=0)  # y >= 0

problem += 5*x + 3*y, "Função Objetivo"

problem += 5*x + 2*y >= 0, "Restrição 1"
problem += x + y <= 7, "Restrição 2"
problem += x <= 5, "Restrição 3"
problem += x >= 0, "Restrição 4"
problem += y >= 0, "Restrição 5"

problem.solve()

print("Status:", pulp.LpStatus[problem.status])

print("Valor de x:", pulp.value(x))
print("Valor de y:", pulp.value(y))

print("Valor da função objetivo:", pulp.value(problem.objective))