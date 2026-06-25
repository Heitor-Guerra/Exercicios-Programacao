CREATE DATABASE cadastro;
USE cadastro;

CREATE TABLE IF NOT EXISTS p (
    id INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(30) NOT NULL,
    nascimento DATE,
    sexo ENUM('M', 'F'),
    altura DECIMAL(3, 2),
    peso DECIMAL(5, 2),
    nacionalidade VARCHAR(15) DEFAULT 'Brasil',
    PRIMARY KEY (id)
);

INSERT INTO p VALUES
-- DML
(DEFAULT, 'Ana', '1980-04-30', 'F', '1.55', '50.86', 'EUA'),
(DEFAULT, 'Pedro', '1998-07-21', 'M', '1.85', '90.49', DEFAULT),
(DEFAULT, 'Arthur', '1999-10-20', 'M', '2.10', '125.87', DEFAULT),
(DEFAULT, 'Sophie', '2003-09-01', 'F', '1.63', '60.35', 'França'),
(DEFAULT, 'Heitor', '2006-06-12', 'M', '1.9', '100.76', DEFAULT),
(DEFAULT, 'Wanessa', '1974-08-05', 'F', '1.64', '62.64', DEFAULT),
(DEFAULT, 'José Rafael', '1972-11-28', 'M', '1.82', '95.35', 'Italia');


-- ---------------------------------------------------------------------------


ALTER TABLE p
RENAME TO pessoas;
-- RENAME TO: Renomeia o nome da tabela

ALTER TABLE pessoas
-- DDL
-- Altera a tabela pessoas
ADD COLUMN profissao VARCHAR(10) DEFAULT 'Desemp' AFTER sexo;
-- Colunas são os dados da tabela
-- ADD: Adiciona coluna (padrão ser no final)
-- AFTER: Coloca a coluna depois do atributo indicado
-- FIRST: Coloca na primeira posição

ALTER TABLE pessoas
MODIFY COLUMN profissao VARCHAR(20) NOT NULL;
-- MODIFY: Modifica a coluna

ALTER TABLE pessoas
CHANGE COLUMN profissao prof VARCHAR(30) NOT NULL DEFAULT 'Desempregado';
-- CHANGE: Muda uma definição para outra


-- -----------------------------------------------------------------------------


DESCRIBE pessoas;
SELECT * FROM pessoas;


ALTER TABLE pessoas
DROP COLUMN prof;
-- DROP: Deleta a coluna

DROP TABLE IF EXISTS curso;
-- DDL

DROP DATABASE IF EXISTS cadastro;
