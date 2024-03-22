import requests
import argparse

API_URL = "http://127.0.0.1:5000/api"


def get(model):
    data = {"model": model}
    response = requests.get(API_URL, json=data)
    print(response)
    return response.json()


def create(model, properties):
    data = {"model": model, "properties": properties}
    response = requests.post(API_URL, json=data)
    return response.json()


def update(model, id, properties):
    data = {"model": model, "id": id, "properties": properties}
    response = requests.put(API_URL, json=data)
    return response.json()


def delete(model, id):
    data = {"model": model, "id": id}
    response = requests.delete(API_URL, json=data)
    return response.json()

def create_dynamic_p(model, arguments):
    dynamic_p = argparse.ArgumentParser(description='Here is description of dynamic arguments')
    for arg_name in arguments:
        dynamic_p.add_argument(f'--{arg_name}')
    return dynamic_p


def main():
    parser = argparse.ArgumentParser(description='Client')

    ARGUMENTS = {
        'producer': ['name', 'age'],
        'series': ['title', 'release_year', 'series_id'],
        'episode': ['title', 'duration', 'episode_id'],
    }

    parser.add_argument('model', type=str, help='Table name')
    parser.add_argument('operation', type=str, help='Operation type', choices=['get', 'create', 'update', 'delete'])
    parser.add_argument('--id', type=int, help='ID of item')
    args, remaining_args = parser.parse_known_args()

    model = args.model
    operation = args.operation
    id = args.id

    dynamic_parser = create_dynamic_p(model, ARGUMENTS.get(model, []))
    args = dynamic_parser.parse_args(remaining_args)

    if operation == 'get':
        print(get(model))
    elif operation == 'create':
        print(create(model, {arg_name: getattr(args, arg_name) for arg_name in ARGUMENTS.get(model, [])}))
    elif operation == 'update':
        print(update(model, id, {arg_name: getattr(args, arg_name) for arg_name in ARGUMENTS.get(model, [])}))
    elif operation == 'delete':
        print(delete(model, id))

if __name__ == "__main__":
    main()