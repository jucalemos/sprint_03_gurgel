# Gurgel — Sprint 4
## Solução final integrada e inovadora | Challenge GoodWe

**Equipe:** [confirmar nomes completos e RMs]  
**Vídeo da Sprint 4:** [inserir link do YouTube não listado]

## 1. Sobre o projeto

O Gurgel é uma proposta de gerenciamento inteligente da recarga de veículos elétricos. O projeto procura reunir monitoramento, gerenciamento de potência, estimativa de custos e informações sobre o uso de energia renovável, com foco em tornar o processo mais claro para o usuário.

Esta documentação diferencia o que está demonstrado no protótipo acadêmico, o que utiliza dados simulados e o que permanece como evolução futura. Essa distinção é importante para que os resultados sejam apresentados com rigor.

## 2. O que o protótipo demonstra

O repositório contém um protótipo de controle em Arduino, scripts Python para calcular a divisão entre potência solar e potência da rede e um conjunto CSV de sessões ilustrativas.

- **Arduino/Tinkercad:** dois potenciômetros representam potência solar e demanda; um botão inicia/encerra a sessão; quatro LEDs indicam estados do sistema; os dados são enviados ao Serial Monitor.
- **Python:** regra de gerenciamento limita a potência liberada a 10 kW e estima a parcela solar e a parcela da rede.
- **Análise de dados:** scripts leem o CSV e calculam totais, médias e gráficos de sessões.
- **Interface e GurAI:** descrevê-los conforme as telas e funcionalidades efetivamente mostradas no protótipo. Não afirmar que controlam o hardware ou realizam pagamentos se isso não foi implementado.

## 3. Arquitetura

A visão geral está em [ARQUITETURA.md](ARQUITETURA.md).

Em alto nível, o projeto contém duas trilhas de demonstração: o circuito simulado com Arduino e os scripts Python que analisam dados CSV. Os arquivos atuais não demonstram uma conexão automática em tempo real entre a placa e o dashboard.

## 4. Gerenciamento de potência

O limite usado no código do Arduino e no script Python é de **10 kW**. Quando a demanda simulada supera esse valor, a potência liberada é limitada. A parcela solar utilizada é calculada como o menor valor entre a potência solar disponível e a potência liberada; o restante é atribuído à rede.

A potência solar e a demanda são entradas simuladas por potenciômetros no circuito. Não são leituras de um sistema fotovoltaico ou de um carregador real.

## 5. Resultados dos dados ilustrativos

O arquivo `python/dados.csv` contém oito registros de sessão. A análise dos registros atuais apresenta:

| Indicador | Resultado do CSV |
|---|---:|
| Número de sessões | 8 |
| Energia total | 75,75 kWh |
| Energia solar simulada | 39,90 kWh |
| Energia da rede simulada | 35,85 kWh |
| Soma do custo informado nas sessões | R$ 88,86 |
| Potência média | 6,725 kW |
| Maior potência registrada no CSV | 9,0 kW |
| Menor potência registrada no CSV | 4,5 kW |

Esses números descrevem o **conjunto de dados ilustrativo** do repositório, não medições físicas. Mais detalhes e limitações estão em [RESULTADOS.md](RESULTADOS.md).

## 6. Relação com o desafio GoodWe

A proposta aborda conceitos relacionados à gestão da demanda, ao uso de energia solar e à visualização de consumo e custos. Esses conceitos são relevantes para ecossistemas energéticos que coordenam geração, armazenamento e consumo.

**Estado atual:** os arquivos analisados não demonstram comunicação direta com inversores, baterias ou carregadores GoodWe. A compatibilidade com equipamentos GoodWe deve ser descrita como alinhamento conceitual e possibilidade de integração futura, salvo se a equipe tiver evidências de uma integração real realizada em outro componente.

## 7. Sustentabilidade

O sistema ilustra como um limite de potência e a consideração de uma fonte solar podem apoiar decisões energéticas mais conscientes. O projeto ainda não comprova uma redução percentual de emissões ou um ganho de eficiência medido; esses impactos devem ser apresentados como benefícios potenciais, não como resultados experimentais.

## 8. Tecnologias identificadas no repositório

- Arduino Uno R3 e simulação Tinkercad;
- C/C++ para Arduino (`.ino`);
- Python;
- pandas;
- NumPy;
- Matplotlib;
- Seaborn;
- CSV;
- GitHub.

Acrescentem apenas outras tecnologias que realmente tenham sido usadas.

## 9. Como executar os scripts Python

Abra um terminal na pasta `python/` e instale as dependências:

```bash
python -m pip install pandas numpy matplotlib seaborn
```

Execute os scripts a partir dessa pasta, porque eles carregam `dados.csv` usando um caminho relativo:

```bash
python gerenciamento.py
python simulacao.py
python dashboard.py
```

## 10. Documentação desta Sprint

- [Arquitetura e fluxo de dados](ARQUITETURA.md)
- [Resultados, metodologia e limitações](RESULTADOS.md)
- [Diagramas funcionais](DIAGRAMAS.md)

## 11. Próximos passos

1. Incluir capturas de tela atuais do protótipo e da interface.
2. Confirmar nomes completos, RMs e link do vídeo não listado.
3. Validar os dados e resultados usados na apresentação.
4. Se houver integração com hardware ou serviços externos, documentar o protocolo, os componentes e as evidências de teste.
5. Manter a distinção entre funcionalidades implementadas, simuladas e planejadas.
