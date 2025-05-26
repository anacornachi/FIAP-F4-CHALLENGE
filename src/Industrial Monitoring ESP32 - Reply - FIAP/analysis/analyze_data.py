"""
Script de análise exploratória para sensores industriais simulados.

Este script:
- Lê os dados coletados do ESP32 e salvos em 'dados.csv'
- Gera três gráficos com matplotlib:
    1. Temperatura e Umidade
    2. Gás e Vibração
    3. Corrente e Pressão

As imagens geradas são salvas em arquivos PNG para documentação e análise visual.
"""

import pandas as pd
import matplotlib.pyplot as plt

def main():
    print("🔍 Lendo o arquivo de dados...")

     # Tenta abrir o arquivo CSV com os dados exportados do ESP32
    try:
        df = pd.read_csv("dados.csv")
    except FileNotFoundError:
        print("⚠️ Arquivo 'dados.csv' não encontrado.")
        return

    print("✅ Dados carregados com sucesso!")

    # Mostrar primeiras linhas
    print("📄 Primeiras linhas dos dados:")
    print(df.head())

    # Gráfico 1: Temperatura e Umidade
    plt.figure(figsize=(10, 5))
    plt.plot(df["temperature"], label="Temperatura (°C)", color="red")
    plt.plot(df["humidity"], label="Umidade (%)", color="blue")
    plt.title("Variação de Temperatura e Umidade")
    plt.xlabel("Amostra")
    plt.ylabel("Valor")
    plt.legend()
    plt.grid(True)
    plt.savefig("grafico_temp_umid.png")
    print("📈 Gráfico 'grafico_temp_umid.png' salvo com sucesso!")

    # Gráfico 2: Gás e Vibração
    plt.figure(figsize=(10, 5))
    plt.plot(df["gasLevel"], label="Gás (MQ2)", color="green")
    plt.plot(df["vibration"], label="Vibração (MPU6050)", color="purple")
    plt.title("Leitura de Gás e Vibração")
    plt.xlabel("Amostra")
    plt.ylabel("Valor")
    plt.legend()
    plt.grid(True)
    plt.savefig("grafico_gas_vibracao.png")
    print("📈 Gráfico 'grafico_gas_vibracao.png' salvo com sucesso!")

    # Gráfico 3: Corrente e Pressão simuladas
    plt.figure(figsize=(10, 5))
    plt.plot(df["current"], label="Corrente", color="orange")
    plt.plot(df["pressure"], label="Pressão", color="teal")
    plt.title("Sensores Simulados - Corrente e Pressão")
    plt.xlabel("Amostra")
    plt.ylabel("Valor")
    plt.legend()
    plt.grid(True)
    plt.savefig("grafico_corrente_pressao.png")
    print("📈 Gráfico 'grafico_corrente_pressao.png' salvo com sucesso!")

    print("✅ Análise concluída.")

# Executa a função principal apenas se o script for chamado diretamente
if __name__ == "__main__":
    main()