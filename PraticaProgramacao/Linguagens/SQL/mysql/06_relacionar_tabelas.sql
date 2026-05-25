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
(DEFAULT, 'Arthur', '1999-10-20', 'M', 'Mecânico', '2.10', '125.87', DEFAULT),
(DEFAULT, 'Sophie', '2003-09-01', 'F', 'Médico', '1.63', '60.35', 'França'),
(DEFAULT, 'Heitor', '2006-06-12', 'M', 'Programador', '1.9', '100.76', 'Italia'),
(DEFAULT, 'Wanessa', '1974-08-05', 'F', 'Gerente', '1.64', '62.64', DEFAULT),
(DEFAULT, 'José Rafael', '1972-11-28', 'M', 'Professor','1.82', '95.35', 'Italia');


CREATE TABLE cursos (
    id INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(30) UNIQUE,
    carga SMALLINT NOT NULL,
    PRIMARY KEY(id)
);


INSERT INTO cursos VALUES 
(DEFAULT, 'MySQL', '30'),
(DEFAULT, 'Python', '45'),
(DEFAULT, 'C++', '65'),
(DEFAULT, 'Java', '100');

ALTER TABLE pessoas
ADD COLUMN curso INT;

ALTER TABLE pessoas
ADD FOREIGN KEY(curso)
REFERENCES cursos(id);

UPDATE pessoas
SET curso = '1'
WHERE id = 3;

UPDATE pessoas
SET curso = '2'
WHERE id = 5;

UPDATE pessoas
SET curso = '1'
WHERE id = 1;

SELECT pessoas.nome, cursos.nome, cursos.carga FROM pessoas JOIN cursos
ON cursos.id = pessoas.curso;


DROP DATABASE cadastro;
