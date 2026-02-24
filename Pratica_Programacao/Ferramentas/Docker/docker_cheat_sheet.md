# Docker Cheat Sheet

## Containers

### Ciclo de vida

* [`docker container create`](https://docs.docker.com/engine/reference/commandline/create) cria um container mas não o inicia.
* [`docker container rename`](https://docs.docker.com/engine/reference/commandline/rename/) permite renomear um container.
* [`docker container run`](https://docs.docker.com/engine/reference/commandline/run) cria e inicia um container em uma única operação
* [`docker container rm`](https://docs.docker.com/engine/reference/commandline/rm) deleta um container
* [`docker container update`](https://docs.docker.com/engine/reference/commandline/update/) atualiza os limites de recurso de um container.

Normalmente, se você rodar um container sem utilizar nenhuma opção ele vai iniciar e parar imediatamente. Se você deseja que ele continue rodando você pode usar o comando `docker run -td <container_id>`. A opção `-t` vai alocar uma sessão pseudo-TTY e o `-d` vai desacomplar o container automaticamente (ou seja, vai rodar o container em background e imprimir o ID do container).

Se você deseja um container transiente, `docker run --rm` vai remover o container assim que ele parar.

Se você deseja mapear um diretório da máquina *host* para o container do Docker, `docker run -v $HOSTDIR:$DOCKERDIR`. Saiba mais em [Volumes](https://github.com/wsargent/docker-cheat-sheet/#volumes).

Se você também deseja remover o  volume associado ao container, ao deletar o container você deve incluir a opção `-v`, por exemplo, `docker rm -v`.

Outra opção muito útil é o `docker run --name <yourname> <docker_image>` porque você pode especificar o `--name` dentro do comando `run` que vai lhe permite iniciar e parar o container através do nome que você especificou quando o criou.


### Iniciando e parando 

* [`docker start`](https://docs.docker.com/engine/reference/commandline/start) inicia um container, então ele passa a rodar.
* [`docker stop`](https://docs.docker.com/engine/reference/commandline/stop) para um container que esteja rodando.
* [`docker restart`](https://docs.docker.com/engine/reference/commandline/restart) para e inicia um container.
* [`docker pause`](https://docs.docker.com/engine/reference/commandline/pause/) pausa um container que esteja rodando, "congelando" ele da maneira que está.
* [`docker unpause`](https://docs.docker.com/engine/reference/commandline/unpause/) vai despausar um container que estava rodando.
* [`docker wait`](https://docs.docker.com/engine/reference/commandline/wait) bloqueia o container até que ele seja parado.
* [`docker kill`](https://docs.docker.com/engine/reference/commandline/kill) envia um SIGKILL para um container que esteja rodando.
* [`docker attach`](https://docs.docker.com/engine/reference/commandline/attach) vai se conectar a um container que esteja rodando.

Se você deseja desacoplar um container que esteja rodando, utilize `Ctrl + p, Ctrl + q`. Se você deseja integrar um container com o [gerenciador de processos do host](https://docs.docker.com/engine/admin/host_integration/), inicialize o daemon com `-r=false` e depois use `docker start -a`.

Se você deseja expor portas do container través do *host*, veja a seção [expondo portas](#exposing-ports).

Políticas de reinicialização para instâncias "crashadas" do docker são [cobridas aqui](http://container42.com/2014/09/30/docker-restart-policies/).

#### Restrições de CPU 

Você pode limitar o uso da CPU, seja usando uma porcentagem de todas as CPUs ou usando *cores* específicos.

Por exemplo, você pode usar a configuração [`cpu-shares`](https://docs.docker.com/engine/reference/run/#/cpu-share-constraint). A configuração é um pouco estranha -- 1024 significa 100% da CPU, então se você quer um container que toma 50% de todos os *cores*, você deve utilizar 512. Veja <https://goldmann.pl/blog/2014/09/11/resource-management-in-docker/#_cpu> para mais:

```
docker run -it -c 512 agileek/cpuset-test
```

Você também pode usar alguns *cores* de uma CPU com o comando [`cpuset-cpus`](https://docs.docker.com/engine/reference/run/#/cpuset-constraint).  Veja <https://agileek.github.io/docker/2014/08/06/docker-cpuset/> para mais detalhes e alguns vídeos bem legais:

```
docker run -it --cpuset-cpus=0,4,6 agileek/cpuset-test
```

Observe que o Docker ainda pode **enxergar** todas as CPUs de dentro do container -- ele apenas não está usando todas elas. Veja <https://github.com/docker/docker/issues/20770> para mais detalhes.


#### Restrições de memória

Você também pode setar [restrições de memória](https://docs.docker.com/engine/reference/run/#/user-memory-constraints) no Docker:

```
docker run -it -m 300M ubuntu:14.04 /bin/bash
```

#### *Capabilities*

Linux *capabilities* podem ser setadas utilizand as opções `cap-add` e `cap-drop`. Veja See <https://docs.docker.com/engine/reference/run/#/runtime-privilege-and-linux-capabilities> para mais detalhes. Elas devem ser utilizadas para aumentar a seguraça do sistema.

Para montar um *filesystem* baseado no FUSE, você precisa combinar tanto `--cap-add` quanto `--device`:

```
docker run --rm -it --cap-add SYS_ADMIN --device /dev/fuse sshfs
```

Para dar acesso a um único *device*:

```
docker run -it --device=/dev/ttyUSB0 debian bash
```

Para dar acesso a todos os *devices*:

```
docker run -it --privileged -v /dev/bus/usb:/dev/bus/usb debian bash
```

Para mais informações sobre privilégios em containers [clique aqui](https://docs.docker.com/engine/reference/run/#runtime-privilege-and-linux-capabilities).

### Info

* [`docker container ls`](https://docs.docker.com/engine/reference/commandline/ps) motra os containers que estão rodando.
* [`docker container logs`](https://docs.docker.com/engine/reference/commandline/logs) obtém um log dos containers. (Você pode usar um log customizado, mas eles estão disponíveis apenas para `json-file` e `journald` na versão 1.10).
* [`docker container inspect`](https://docs.docker.com/engine/reference/commandline/inspect) olha para todas as informações de um container (incluindo o endereço IP).
* [`docker container events`](https://docs.docker.com/engine/reference/commandline/events) obtém os eventos de um container.
* [`docker container port`](https://docs.docker.com/engine/reference/commandline/port) mostra a porta pública de um container.
* [`docker container top`](https://docs.docker.com/engine/reference/commandline/top) mostra os processos rodando dentro de um container.
* [`docker container stats`](https://docs.docker.com/engine/reference/commandline/stats) mostra uma estatística dos recursos que o container está utilizando.
* [`docker container diff`](https://docs.docker.com/engine/reference/commandline/diff) mostra os arquivos alterados pelo FS de um container.

`docker ps -a` mostra os containers que estão rodando e os que foram parados.

`docker stats --all` mostra uma lista de todos os containers. O padrão é mostrar apenas os que estão rodando.

### Importar / Exportar

* [`docker cp`](https://docs.docker.com/engine/reference/commandline/cp) copia arquivos ou pastas entre o container e o *filesystem* local.
* [`docker export`](https://docs.docker.com/engine/reference/commandline/export) transforma o *filesystem* do container em um fluxo de arquivo *tarball* para STDOUT.


### Executando comandos

* [`docker exec`](https://docs.docker.com/engine/reference/commandline/exec) executa um comando dentro do container.

Por exemplo, para entrar em um container fictício, que esteja rodando, chamado foo, inclua um shell a ele da seguinte maneira: `docker exec -it foo /bin/bash`.

## Imagens

Imagens são apenas [templates de um container docker](https://docs.docker.com/engine/understanding-docker/#how-does-a-docker-image-work).

### Ciclo de vida

* [`docker image ls`](https://docs.docker.com/engine/reference/commandline/images) mostra todas as imagens.
* [`docker image import`](https://docs.docker.com/engine/reference/commandline/import) cria uma imagem a partir de um *tarball*.
* [`docker build`](https://docs.docker.com/engine/reference/commandline/build) cria uma imagem a partir de um Dockerfile.
* [`docker commit`](https://docs.docker.com/engine/reference/commandline/commit) cria uma imagem a partir de um container, pausando ele temporariamente caso ele esteja rodando.
* [`docker image rm`](https://docs.docker.com/engine/reference/commandline/rmi) remove uma imagem.
* [`docker image load`](https://docs.docker.com/engine/reference/commandline/load) carrega uma imagem a partir de um arquivo tar no STDIN, incluindo imagess and tags (a partir da versão 0.7).
* [`docker image save`](https://docs.docker.com/engine/reference/commandline/save) salva uma imagem em um arquivo tar através do STDOUT com todas as camadas pais, tags e versões (a partir do 0.7).

### Info

* [`docker history`](https://docs.docker.com/engine/reference/commandline/history) mostra o histórico de todas as imagens.
* [`docker tag`](https://docs.docker.com/engine/reference/commandline/tag) dar uma tag a uma imagem (local ou *registry*)


### Fazendo uma limpeza

Você pode utilizar o comando `docker rmi` para remover imagens específicas, porém, existe uma ferramenta chamada [docker-gc](https://github.com/spotify/docker-gc), que de maneira segura, limpa as imagens que não está sendo utilizada por nenhum container. 

 that will safely clean up images that are no longer used by any containers. A partir do docker 1.13, o comando `docker image prune` também está disponível para remover imagens que não estão sendo usadas. Veja a seção [Prune](#prune).

### Carregar/Salvar imagens

Carregue uma imagem a partir do arquivo:
```
docker load < my_image.tar.gz
```

Salve uma imagem existente usando:
```
docker save my_image:my_tag | gzip > my_image.tar.gz
```

### Importar/Exportar containers


Importe um container com uma imagem a partir de um arquivo:
```
cat my_container.tar.gz | docker import - my_image:my_tag
```

Exporte um container existente usando:
```
docker export my_container | gzip > my_container.tar.gz
```

### Diferenças entre carregar uma imagem salva e importar um container exportado como uma imagem

Carregar uma imagem usanfo o comando `load` cria uma nova imagem, incluindo o seu histórico. Importar um container como uma imagem usando o comando `import` cria uma nova imagem excluindo o seu histórico, o que resulta em uma imamgem de tamanho menor do que usando o comando anterior.

## Rede

O Docker possui *features* de [rede](https://docs.docker.com/engine/userguide/networking/). Automaticamente, ele cria 3 interfaces de rede quando você o instala (*bridge*, *host*, *none*). Um novo container é inicializado, por padrão, dentro da rede *bridge*. Para habilitar a comunicação entre multiplos containers, você pode criar uma nova rede e iniciarlizar o mesmo com ela. Isso vai habilitar a comunicação entre os containers dentro dela ao mesmo tempo que os isola dos outros containers que não estejam conectados nesta rede. Além disso, isso permite mapear os nomes dos containers com o seus respectivos endereços IP. Veja [trabalhando com redes](https://docs.docker.com/engine/userguide/networking/work-with-networks/) para mais detalhes.

### Ciclo de vida

* [`docker network create <name>`](https://docs.docker.com/engine/reference/commandline/network_create/)  cria uma nova rede (tipo padrão: *bridge*).
* [`docker network rm <name>`](https://docs.docker.com/engine/reference/commandline/network_rm/) remode uma ou mais redes especificadas pelo nome ou identificador. Nenhum container pode se conectar em uma rede quando deletada.

### Info

* [`docker network ls`](https://docs.docker.com/engine/reference/commandline/network_ls/) lista todas as redes.
* [`docker network inspect <name>`](https://docs.docker.com/engine/reference/commandline/network_inspect/) mostra informações detalhadas de uma ou mais redes.

### Conexão

* [`docker network connect <network> <container>`](https://docs.docker.com/engine/reference/commandline/network_connect/) Conecta um container a uma rede
* [`docker network disconnect <network> <container>`](https://docs.docker.com/engine/reference/commandline/network_disconnect/) Desconecta um container de uma rede

Você pode especificar um [endereço IP para um container](https://blog.jessfraz.com/post/ips-for-all-the-things/):

```
# cria uma nova rede bridge com sua subnet e gateway para seu bloco de endereço IP
docker network create --subnet 203.0.113.0/24 --gateway 203.0.113.254 iptastic

# roda um container nginx com um IP específico para o dado bloco
$ docker run --rm -it --net iptastic --ip 203.0.113.2 nginx

# da um culr no IP a partir de qualquer outro local (assumindo que este seja um IP público)
$ curl 203.0.113.2
```

## Registry & Repositório

Um repositório é uma coleção *hosteada* de imagens com tagas que juntas criam um sistema de arquivo para um container;

Um *registry* é um *host* -- ou seja, um servidor que armazena repositórios e disponibiliza um API HTTP para [gerencias o upload e download dos repositórios](https://docs.docker.com/engine/tutorials/dockerrepos/).

O Docker.com *hostea* seus prórpios [índices](https://hub.docker.com/) em uma central de *registries* qie contém um grande número de repositórios. Sendo assim, essa central [não é muito boa em verificar a procedência das imagens](https://titanous.com/posts/docker-insecurity) e deve ser evitada caso segurança seja algo crítico para você.
 

* [`docker login`](https://docs.docker.com/engine/reference/commandline/login) efetua login em um *registry*.
* [`docker logout`](https://docs.docker.com/engine/reference/commandline/logout) efetua logout de um *registry*.
* [`docker search`](https://docs.docker.com/engine/reference/commandline/search) busca imagens dentro do *registry*.
* [`docker pull`](https://docs.docker.com/engine/reference/commandline/pull) efetua um *pull* de uma imagem do *registry* para sua máquina local.
* [`docker push`](https://docs.docker.com/engine/reference/commandline/push) efetua um *push* de uma imagem para o *registry* a partir da sua máquina local.

### Rodando um *registry* local

Você pode rodar um *registry* local utilizando o projeto de [distribuição docker](https://github.com/docker/distribution) e seguindo as instruções de [*deploy* local](https://github.com/docker/docker.github.io/blob/master/registry/deploying.md).

Além disso, você pode se interessar pela [lista de emails](https://groups.google.com/a/dockerproject.org/forum/#!forum/distribution).

## Dockerfile

[O arquivo de configuração](https://docs.docker.com/engine/reference/builder/). Prepara um container Docker quando você executa o comando `docker build`. A maioria das pessoas preferem este comando do que o `docker commit`.  

Estes são alguns dos editores de texto que dão suporte, em termos de módulos que destacam a sintaxe, para criar Dockerfiles:
* Se você utiliza o [jEdit](http://jedit.org), eu adicionei um módulo para destacar de sintaxe para o [Dockerfile](https://github.com/wsargent/jedit-docker-mode). Sinta-se livre para usar.
* [Sublime Text 2](https://packagecontrol.io/packages/Dockerfile%20Syntax%20Highlighting)
* [Atom](https://atom.io/packages/language-docker)
* [Vim](https://github.com/ekalinin/Dockerfile.vim)
* [Emacs](https://github.com/spotify/dockerfile-mode)
* [TextMate](https://github.com/docker/docker/tree/master/contrib/syntax/textmate)
* [VS Code](https://github.com/Microsoft/vscode-docker)
* Veja também [Docker meets the IDE](https://domeide.github.io/)

### Instruções

* [.dockerignore](https://docs.docker.com/engine/reference/builder/#dockerignore-file)
* [FROM](https://docs.docker.com/engine/reference/builder/#from) Prepara a imagem base para as instruções subsequentes.
* [MAINTAINER (depreciado - use a tag LABEL)](https://docs.docker.com/engine/reference/builder/#maintainer-deprecated) Define o autor que gerou a imagem.
* [RUN](https://docs.docker.com/engine/reference/builder/#run) executa qualquer comando em uma nova camada em cima de uma imagem e *comita* o resultado.
* [CMD](https://docs.docker.com/engine/reference/builder/#cmd) fornecer padrões para um container em execução.
* [EXPOSE](https://docs.docker.com/engine/reference/builder/#expose) informa o Docker que o container pode escutar uma determinada porta de rede durante o tempo de execução. NOTA: isso não faz com que a porta seja acessível.
* [ENV](https://docs.docker.com/engine/reference/builder/#env) define uma variável de ambiente.
* [ADD](https://docs.docker.com/engine/reference/builder/#add) copia novos arquivos, diretórios, ou arquivos remotos em um container. Invalida cache. Evite usar `ADD` e use o comando `COPY`.
* [COPY](https://docs.docker.com/engine/reference/builder/#copy) copia um novo arquivo ou diretórios para dentro do container. Por padrão copia como root independente das configurações do USER/WORKDIR. Utilize `--chown=<user>:<group>` para poderes de acesso a outros usuários/grupos. (o mesmo é válido para o comando `ADD`.)
* [ENTRYPOINT](https://docs.docker.com/engine/reference/builder/#entrypoint) configura um container que vai rodar como um executável.
* [VOLUME](https://docs.docker.com/engine/reference/builder/#volume) cria um ponto de montagem para montar volumes externos ou outros containers.
* [USER](https://docs.docker.com/engine/reference/builder/#user) define o nome de usuário para os seguintes comandos: RUN / CMD / ENTRYPOINT.
* [WORKDIR](https://docs.docker.com/engine/reference/builder/#workdir) define o diretório de trabalho.
* [ARG](https://docs.docker.com/engine/reference/builder/#arg) define uma variável que existe durante o tempo de execução do *build*.
* [ONBUILD](https://docs.docker.com/engine/reference/builder/#onbuild) adicionar uma instrução alarme que dispara quando a imagem está sendo usada como base para outra *build*.
* [STOPSIGNAL](https://docs.docker.com/engine/reference/builder/#stopsignal) define o sinal de alerta do sistema que vai ser enviado para sair do container.
* [LABEL](https://docs.docker.com/config/labels-custom-metadata/) aplica uma chave/valor para suas imagens, containers, ou *daemons*.
* [SHELL](https://docs.docker.com/engine/reference/builder/#shell) sobrecarrega o shell padrão para rodar os comandos do docker.
* [HEALTHCHECK](https://docs.docker.com/engine/reference/builder/#healthcheck) informa docker como testar o container para testar se tudo está funcionando adequadamente.

### Tutorial

* [Tutorial do Flux7 para o Dockerfile](https://www.flux7.com/tutorial/docker-tutorial-series-part-3-automation-is-the-word-using-dockerfile/)

### Exemplos

* [Exemplos](https://docs.docker.com/engine/reference/builder/#dockerfile-examples)
* [Boas práticas para escrever Dockerfiles](https://docs.docker.com/engine/userguide/eng-image/dockerfile_best-practices/)
* [Michael Crosby](http://crosbymichael.com/) tem mais algumas [boas práticas para criar Dockerfiles](http://crosbymichael.com/dockerfile-best-practices.html) / [parte 2](http://crosbymichael.com/dockerfile-best-practices-take-2.html).
* [Construindo boas imagens Docker](http://jonathan.bergknoff.com/journal/building-good-docker-images) / [Construindo imagens Dockers ainda melhores](http://jonathan.bergknoff.com/journal/building-better-docker-images)
* [Gerenciando a configuração de um container com metadados](https://speakerdeck.com/garethr/managing-container-configuration-with-metadata)
* [Como escrever excelentes Dockerfiles](https://rock-it.pl/how-to-write-excellent-dockerfiles/)

## Camadas

O versionamento dos arquivos de sistema do docker é feito em camadas. Elas funcionam como [comits no git ou *changesets* para arquivos de sistemas](https://docs.docker.com/engine/userguide/storagedriver/imagesandcontainers/).

## Links

Links são como os containers Docker conversam uns com os outros [através de portas TCP/IP](https://docs.docker.com/engine/userguide/networking/default_network/dockerlinks/). [Atlassian](https://blogs.atlassian.com/2013/11/docker-all-the-things-at-atlassian-automation-and-wiring/) mostra alguns exemplos funcionais. Você também pode determinar [links pelo hostname](https://docs.docker.com/engine/userguide/networking/default_network/dockerlinks/#/updating-the-etchosts-file).

Este está depreciado para estender algumas [redes definidas por usuário](https://docs.docker.com/network/).

NOTA: se você deseja que os containers comuniquem uns com os outros apenas utilizando links, inicie o do docker daemon com `-icc=false` para desebilitar os processor de intra-comunicação. 

Se você possui um container com nome CONTAINER (especificado por `docker run --name CONTAINER`) e em um Dockerfile, ele possui uma porta exposta:

```
EXPOSE 1337
```

Então, se nós criarmos qualquer outro container chamado LINKED como este:

```
docker run -d --link CONTAINER:ALIAS --name LINKED user/wordpress
```

Então, as portas expostas e os *aliases* do CONTAINER serão mostrados em LINKED com as seguintes variáveis de ambiente:

```
$ALIAS_PORT_1337_TCP_PORT
$ALIAS_PORT_1337_TCP_ADDR
```

Você pode se conectar nele dessa maneira.

Para deletar os links, utilize o comando `docker rm --link`.

Geralmente, a *linkagem* entre serviços docker é um subconjunto de um "descobrimento de serviço", um grande problema caso você esteja planejando usar Docker para escalar em produção. Você pode se referir ao livro [The Docker Ecosystem: Service Discovery and Distributed Configuration Stores](https://www.digitalocean.com/community/tutorials/the-docker-ecosystem-service-discovery-and-distributed-configuration-stores) para mais informações.

## Volumes

Os volumes no Docker são [arquivos de sistemas flutuantes](https://docs.docker.com/engine/tutorials/dockervolumes/). Eles não possuem uma conexão particular com um container. Você pode usar volumes montados a partir de [container somente de dados](https://medium.com/@ramangupta/why-docker-data-containers-are-good-589b3c6c749e) para fins de portabilidade. A partir do Docker 1.9.0, o Docker passou a nomear volumes que substituem containers apenas de dados. Considere usar volumes nomeados para implementar isso ao invés de containers de dados.

### Ciclo de vidar

* [`docker volume create`](https://docs.docker.com/engine/reference/commandline/volume_create/)
* [`docker volume rm`](https://docs.docker.com/engine/reference/commandline/volume_rm/)

### Informações

* [`docker volume ls`](https://docs.docker.com/engine/reference/commandline/volume_ls/)
* [`docker volume inspect`](https://docs.docker.com/engine/reference/commandline/volume_inspect/)

Volumes são úteis em situações em que você não quer usar links (que são apenas TCP/IP). Por exemplo, se você precisar ter duas instancias docker comunicando através de algo deixado no arquivo de sistema.

Você pode montar vários containers docker de uma vez usando o comando `docker run --volumes-from`.

Como os volumes são sistemas de arquivos isolados, frequentemente, eles são usados para armazenar estados de alguma computação que é transiente no container. Isto é, você pode ter um container sem estado e transiente continuado de ponto que útimo container deixou.

Veja [volumes avançados](http://crosbymichael.com/advanced-docker-volumes.html) para mais detalhes. [Container42](http://container42.com/2014/11/03/docker-indepth-volumes/) também é bem útil.

Você pode [mapear diretórios hosts do MacOS como volumes docker](https://docs.docker.com/engine/tutorials/dockervolumes/#mount-a-host-directory-as-a-data-volume):

```
docker run -v /Users/wsargent/myapp/src:/src
```

Você pode usar columes NFS remotos se você estiver se 
You can use remote NFS volumes if you're [sentindo corajoso](https://docs.docker.com/engine/tutorials/dockervolumes/#/mount-a-shared-storage-volume-as-a-data-volume).

Você também pode considerar rodar containers apenas de dados como descrito [aqui](http://container42.com/2013/12/16/persistent-volumes-with-docker-container-as-volume-pattern/) para obter uma certa portabilidade de dados.

Saiba que você pode [montar arquivos como volumes](#volumes-can-be-files).

## Expondo portas


Expor as portas de entrada através do container *host* é [complicado, mas factível](https://docs.docker.com/engine/reference/run/#expose-incoming-ports).

Isso é feito mapeando a porta do container para com a porta do *host* (apenas usando a interface *localhost*) usando a opção `-p`:

```
docker run -p 127.0.0.1:$HOSTPORT:$CONTAINERPORT --name CONTAINER -t ALGUMA_IMAGEM
```

Você pode informar ao Docker que o container escuta uma porta de rede específica durante a execução ao usar o comando [EXPOSE](https://docs.docker.com/engine/reference/builder/#expose):

```
EXPOSE <CONTAINERPORT>
```

Note que `EXPOSE` não expões a porta propriamente dita -- apenas a opção `-p` faz isso. Para expor uma porta do container na sua porta *localhost*:

```
iptables -t nat -A DOCKER -p tcp --dport <LOCALHOSTPORT> -j DNAT --to-destination <CONTAINERIP>:<PORT>
```

Se você estiver rodando Docker em uma VirtualBox, então você precisa encaminha a porta para lá também usando uma [*forwarded_port*](https://docs.vagrantup.com/v2/networking/forwarded_ports.html). Defina um intervalo de portas que no seu *Vagrantfile* dessa maneira para que vcê possa mapeá-las dinamicamente:

```
Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  ...

  (49000..49900).each do |port|
    config.vm.network :forwarded_port, :host => port, :guest => port
  end

  ...
end
```

Se você esquecer o que você mapeou na porta do seu container *host*, utilize `docker port` para mostrar o que você fez:

```
docker port CONTAINER $CONTAINERPORT
```


## Docker-Compose

*Compose* é uma ferramenta para definir e rodar aplicações em vários containers Docker. Com o *compose* você utiliza uma arquivo YAML para configurar os serviços de sua aplicação. Na sequência, com uum único comando, você cria e inicia todos os serviços a partir da sua configuração. Para aprender mais sobre todas as funcionalidades do *Compose*, veja a [lista de funcionalidades](https://docs.docker.com/compose/overview/#features).

Ao usar este comando, você inicia sua aplicação:

```
docker-compose -f <docker-compose-file> up
```

Você também pode rodar `docker-compose` de maneira desacoplada usando a opção `-d` e parar ele quando quiser utilizando o comando:

```
docker-compose stop
```
Você pode desligar tudo
Você pode desligar tudo, remover os containers inteiramente, com o comando `down`. Passe `--volumes` para remover também o dados.


## Dicas

### *Prune*

Os novos [comandos de gerenciamento de dados](https://github.com/docker/docker/pull/26108) chegaram no Docker 1.13:

* `docker system prune`
* `docker volume prune`
* `docker network prune`
* `docker container prune`
* `docker image prune`

### Comitar com comandos (precisa de um Dockerfile)

```
docker commit -run='{"Cmd":["postgres", "-too -many -opts"]}' $(dl) postgres
```

### Obter o endereço IP

```
docker inspect $(dl) | grep -wm1 IPAddress | cut -d '"' -f 4
```

ou com [jq](https://stedolan.github.io/jq/) instalado:

```
docker inspect $(dl) | jq -r '.[0].NetworkSettings.IPAddress'
```

ou usando o [template go](https://docs.docker.com/engine/reference/commandline/inspect):

```
docker inspect -f '{{ .NetworkSettings.IPAddress }}' <container_name>
```

ou quando *buildando* um imagem com Dockerfile, quando você quiser passar um argumento de build:

```
DOCKER_HOST_IP=`ifconfig | grep -E "([0-9]{1,3}\.){3}[0-9]{1,3}" | grep -v 127.0.0.1 | awk '{ print $2 }' | cut -f2 -d: | head -n1`
echo DOCKER_HOST_IP = $DOCKER_HOST_IP
docker build \
  --build-arg ARTIFACTORY_ADDRESS=$DOCKER_HOST_IP 
  -t sometag \
  some-directory/
```

### Monitorar os recursos utilizados pelos containers

Para verificar CPU, memória, ou I/O de rede em um único container, você pode usar:
To check the CPU, memory, and network I/O usage of a single container, you can use:
```
docker stats <container>
```

Para todos os containers listados por imagem:
```
docker ps -a -f ancestor=ubuntu
```


### Volumes podem ser arquivos

Saiba que você pode montar arquivos como volumes. Por exemplo, se você pode injetar uma configuração dessa forma:

``` bash
# copia o arquivo para o container
docker run --rm httpd cat /usr/local/apache2/conf/httpd.conf > httpd.conf

# edita o arquivo
vim httpd.conf

# inicia o container com a configuração que foi modificada
docker run --rm -it -v "$PWD/httpd.conf:/usr/local/apache2/conf/httpd.conf:ro" -p "80:80" httpd
```
