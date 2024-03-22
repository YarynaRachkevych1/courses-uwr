from flask import Flask, request, jsonify
from models import models, db
from datetime import date

def create_app():
    app = Flask(__name__)
    app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///database.db'
    db.init_app(app)

    with app.app_context():
        db.create_all()

    return app

app = create_app()

@app.route('/api', methods=['POST'])
def create_item():
    try:
        data = request.get_json()
        if 'date' in data['properties']:
            data['properties']['date'] = date.fromisoformat(
                data['properties']['date'])
        db.session.add(models[data['model']](**data['properties']))
        db.session.commit()
        return jsonify({'message': 'Item created successfully'}), 201
    except Exception as e:
        return jsonify({'error': str(e)}), 400

@app.route('/api', methods=['GET'])
def get_all_items():
    try:
        data = request.get_json()
        items = models[data['model']].query.all()
        return jsonify([item.serialize() for item in items])
    except Exception as e:
        return jsonify({'error': str(e)}), 400

@app.route('/api', methods=['PUT'])
def update_item():
    try:
        data = request.get_json()
        if 'date' in data['properties']:
            data['properties']['date'] = date.fromisoformat(
                data['properties']['date'])
        item = models[data['model']].query.get(data['id'])
        if not item:
            return jsonify({'message': 'Item not found'}), 404

        for key, value in data['properties'].items():
            setattr(item, key, value)
        db.session.commit()
        return jsonify({'message': 'Item updated successfully'})
    except Exception as e:
        return jsonify({'error': str(e)}), 400

@app.route('/api', methods=['DELETE'])
def delete_item():
    try:
        data = request.get_json()
        item = models[data['model']].query.get(data['id'])
        if not item:
            return jsonify({'message': 'Item not found'}), 404

        db.session.delete(item)
        db.session.commit()
        return jsonify({'message': 'Item deleted successfully'})
    except Exception as e:
        return jsonify({'error': str(e)}), 400

if __name__ == '__main__':
    app.run(debug=True)