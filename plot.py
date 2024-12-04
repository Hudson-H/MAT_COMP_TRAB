import matplotlib.pyplot as plt
import numpy as np

def plot_sin_and_error(file_name):
    # Inicializa listas para armazenar os dados
    angles = []
    vitor_sin_values = []
    original_sin_values = []
    errors = []

    # Lê os dados do arquivo
    try:
        with open(file_name, 'r') as file:
            next(file)  # Pula a primeira linha (cabeçalho)
            for line in file:
                angle, vitor_sin, original_sin, error = map(float, line.strip().split(','))
                angles.append(angle)
                vitor_sin_values.append(vitor_sin)
                original_sin_values.append(original_sin)
                errors.append(error)
    except FileNotFoundError:
        print(f"Erro: Arquivo '{file_name}' não encontrado.")
        return

    # Plota o gráfico do seno
    plt.figure(figsize=(10, 6))
    plt.plot(angles, original_sin_values, label='Seno Original', color='blue')
    plt.plot(angles, vitor_sin_values, label='vitor_sin', linestyle='--', color='red')
    plt.title('Comparação entre o Seno Original e vitor_sin')
    plt.xlabel('Ângulo (rad)')
    plt.ylabel('Valor do Seno')
    plt.legend()
    plt.grid()
    plt.show()

    # Plota o gráfico do erro
    plt.figure(figsize=(10, 6))
    plt.plot(angles, errors, label='Erro (|Seno Original - vitor_sin|)', color='green')
    plt.title('Erro Absoluto entre o Seno Original e vitor_sin')
    plt.xlabel('Ângulo (rad)')
    plt.ylabel('Erro')
    plt.legend()
    plt.grid()
    plt.show()

# Chama a função para plotar
plot_sin_and_error("errors_sin.txt")
