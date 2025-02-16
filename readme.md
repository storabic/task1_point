﻿Проект №1: Точка (MIT)
=============================    

## Структура проекта

Проект структурирован в соответствии с принятыми стандартами и содержит следующие каталоги верхнего уровня:

* `/docs` — документация: задание, комментарии и автособираемая [doxygen-документация][lp_doxydoc] на код;
* `/src` — исходные платформо-мало-или-почти-независимые коды;
* `/tests` — тесты
* `readme.md` — ридмишка с комментариями к содержимому текущего каталога в формате Markdown. Чтобы просмотреть локальную версию файла с красивым форматированием, можно открыть в Firefox с установленным каким-то там плагином.

### Версионируемые файлы

Файлы с расширением `.example` являются т.н. "образцовыми". Они содержат user-specific данные, поэтому их нельзя помещать в репозиторий под своими именами. Каждый пользователь должен сделать локальную копию такого файла, убрав расширение `.example`, и отредактировав его в соответствии со своими локальными настройками.

Пример: файл `doxyit.cmd.example` является примером командного файла автоматизации запуска построения doxygen-документации. Так как у каждого пользователя расположение исполняемых файлов doxygen может изменяться, данный файл поставляется в виде примера. Необходимо сделать локальную копию `doxyit.cmd`, настроить пути внутри и использовать по назначению.


[comment]: <> (было так: [lp_doxydoc]: docs/doxydoc/readme.md, но путь надо давать относительно каталога с Doxyfile!)
[lp_doxydoc]: readme.md