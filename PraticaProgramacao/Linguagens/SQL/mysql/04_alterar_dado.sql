CREATE DATABASE cadastro;
USE cadastro;

CREATE TABLE IF NOT EXISTS pessoas (
    id INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(30) NOT NULL,
    nascimento DATE,
    sexo ENUM('M', 'F'),
    profissao VARCHAR(20) DEFAULT 'Desempregado',
    altura DECIMAL(3, 2),
    peso DECIMAL(5, 2),
    nacionalidade VARCHAR(15) DEFAULT 'Brasil',
    PRIMARY KEY (id)
);

INSERT INTO pessoas VALUES
(DEFAULT, 'Ana', '1980-04-30', 'F', 'Médico', '1.55', '50.86', 'EUA'),
(DEFAULT, 'Pedro', '1998-07-21', 'M', 'Pedreiro', '1.85', '90.49', DEFAULT),
(DEFAULT, 'Arthur', '1999-10-20', 'M', 'Mecânico', '2.10', '125.87', DEFAULT),
(DEFAULT, 'Sophie', '2003-09-01', 'F', 'Médico', '1.63', '60.35', 'França'),
(DEFAULT, 'Eitor', '2006-06-12', 'M', 'Programador', '1.9', '100.76', 'Italia'),
(DEFAULT, 'Wanessa', '1974-08-05', 'F', 'Gerente', '1.64', '62.64', DEFAULT),
(DEFAULT, 'José Rafael', '1972-11-28', 'M', 'Professor','1.82', '95.35', 'Italia');


-- --------------------------------------------------------------------------


UPDATE pessoas
-- UPDATE: Atualizar uma tabela
SET nome = 'Heitor', peso = '101.8', altura = '1.91' 
WHERE id = 5
LIMIT 1;
-- SET: Define o dado novo
-- WHERE: Onde o dado condiz
-- LIMIT: Limita o número de linhas afetadas

DELETE FROM pessoas
WHERE id = 1;
-- DELETE: Apaga as linhas
DELETE FROM pessoas
WHERE id = 2;

-- Se o WHERE nao for especificado as alterações se aplicam a tudo


-- --------------------------------------------------------------------------

SELECT * FROM pessoas;

DROP DATABASE IF EXISTS cadastro;
