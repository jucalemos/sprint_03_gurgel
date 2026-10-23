# Diagramas funcionais — Gurgel Sprint 4

Os diagramas abaixo representam os fluxos documentados no repositório. Eles não indicam uma conexão automática entre os scripts Python e o circuito Arduino.

## 1. Circuito de monitoramento e controle

```mermaid
flowchart TD
    A[Potenciômetro A0<br/>Potência solar simulada] --> C[Arduino Uno]
    B[Potenciômetro A1<br/>Demanda simulada] --> C
    D[Botão no pino 7] --> C
    C --> E{Sessão ativa?}
    E -- Não --> F[Esperar acionamento]
    E -- Sim --> G[Calcular potência liberada]
    G --> H[Estimar solar utilizada e rede]
    H --> I[Atualizar energia e custo]
    I --> J[Exibir no Serial Monitor]
    G --> K[Acender LED de status]
```

## 2. Análise do CSV

```mermaid
flowchart LR
    A[dados.csv<br/>8 sessões ilustrativas] --> B[pandas]
    B --> C[Totais e médias]
    B --> D[Histórico por sessão]
    B --> E[Gráficos]
    E --> F[Energia por sessão]
    E --> G[Custo por sessão]
    E --> H[Potência por sessão]
    E --> I[Solar versus rede]
```

## 3. Conceito de gerenciamento energético

```mermaid
flowchart TD
    A[Demanda simulada] --> C[Comparar com limite de 10 kW]
    B[Potência solar simulada] --> D[Calcular parcela solar disponível]
    C --> E[Potência liberada]
    E --> D
    D --> F[Estimar parcela da rede]
    F --> G[Apresentar valores e estado]
```

## 4. Imagem do circuito

A equipe enviou uma captura do circuito Arduino Uno com dois potenciômetros, botão e quatro LEDs. Salvem a imagem no repositório como `Sprint4/imagens/circuito-arduino.png` e adicionem abaixo uma referência Markdown:

```markdown
![Circuito do protótipo Gurgel no Tinkercad](imagens/circuito-arduino.png)
```

Não é possível inserir automaticamente a imagem que foi enviada no chat diretamente no repositório sem que o arquivo de imagem esteja disponível para upload. Salvem a imagem original e façam o upload para essa pasta.
