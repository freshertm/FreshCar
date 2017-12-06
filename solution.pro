TEMPLATE=subdirs
SUBDIRS=box2d glm qjson \ #v2 app test
    src/V3
CONFIG += ordered

box2d.file=lib/Box2D/Box2D.pro
glm.file=lib/glm/glm.pro
qjson.file=lib/QJson/QJson.pro
#
#v2.file=src/V2/V2.pro
#v2.depends=box2d glm
#
#app.file=src/mycar.pro
#app.depends=v2 glm
#test.file=test/tests.pro



