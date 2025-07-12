# Qt Supervisory Client/Server

Este projeto é um sistema cliente/servidor para supervisão e visualização gráfica de dados, implementado com **Qt** em C++.  
Ele permite que um servidor armazene valores associados a timestamps, enquanto clientes podem produzir novos valores (*Producer*) ou consumir e visualizar esses valores em um gráfico em tempo real (*Consumer*).

## Componentes

- **Producer**  
  Cliente responsável por enviar (produzir) valores para o servidor junto com timestamps.  
  **Criador:** *Aysllan Paulo de Macedo*

- **Consumer**  
  Cliente responsável por requisitar (consumir) valores do servidor e exibi-los em um gráfico dinâmico.  
  **Criador:** *Gabriel Figueiredo Gonzaga*

- **Servidor**  
  Armazena os valores enviados pelos *Producers* e atende às requisições dos *Consumers*.  
  Pode atender múltiplos clientes simultaneamente.

## Como executar

1. Compile os três programas (Servidor, Producer, Consumer) separadamente usando Qt Creator ou `qmake`/`make`.
2. Execute o servidor em uma máquina.
3. Execute um ou mais *Producers* para enviar valores ao servidor.
4. Execute um ou mais *Consumers* para visualizar os dados em tempo real.

## Licença

Uso acadêmico/educacional.
