from flask import Flask, flash, render_template, redirect, url_for, request, session
from flask_restful import reqparse, abort, Api, Resource
from module.database import Database
from sense_hat import SenseHat

import json

app = Flask(__name__)
app.secret_key = "mys3cr3tk3y"
db = Database()
api = Api(app)

TODOS = {
    'todo1': {'task': 'build an API'},
    'todo2': {'task': '?????'},
    'todo3': {'task': 'profit!'},
}


def abort_if_todo_doesnt_exist(id):
    if id not in TODOS:
        abort(404, message="Todo {} doesn't exist".format(id))

parser = reqparse.RequestParser()
parser.add_argument('temp')
parser.add_argument('humidity')
parser.add_argument('pressure')


# Todo
# shows a single todo item and lets you delete a todo item
class Todo(Resource):
    def get(self, id):
        data = db.read(id);
        return data

    def delete(self, id):
        abort_if_todo_doesnt_exist(id)
        del TODOS[id]
        return '', 204

    def put(self, id):
        args = parser.parse_args()
        db.insert(args)
        return args,201 




# TodoList
# shows a list of all todos, and lets you POST to add new tasks
class TodoList(Resource):
    def get(self):
        datas = db.read(None);
        return datas

    def post(self):
        args = parser.parse_args()
        id = int(max(TODOS.keys()).lstrip('todo')) + 1
        id = 'todo%i' % id
        TODOS[id] = {'task': args['task']}
        return TODOS[id], 201


class InsertWeather(Resource):
    def get(self):
        hat = SenseHat()
        hat.clear()
        readings = dict()
        readings["temp"] = hat.temperature
        readings["humidity"] = hat.humidity
        readings["pressure"] = hat.pressure
        for key in readings.copy():
            if key in {"temp", "humidity", "pressure"}:
                readings[key] = round(readings[key], 2)
        insertdata = json.dumps(readings)        
        db.insert(readings)
        return readings,201




##
## Actually setup the Api resource routing here
##
api.add_resource(TodoList, '/getWeathers')
api.add_resource(Todo, '/getWeathers/<id>')
api.add_resource(InsertWeather, '/insertWeathers/')



if __name__ == "__main__":
    app.debug = True
    app.run(host='0.0.0.0', port=8181)


