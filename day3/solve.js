const points = [
    {
        name: "A",
        x: -1,
        y: 1,
        time: 2.3,
    },
    {
        name: "B",
        x: 4,
        y: 5,
        time: 1,
    },
    {
        name: "C",
        x: 2,
        y: 7,
        time: 2.5,
    },
    {
        name: "D",
        x: -4,
        y: 4,
        time: 0.45,
    },
];

const copyObject = (object) => {
    const newObject = JSON.parse(JSON.stringify(object));

    return newObject;
};

// Return the distance between 2 points
const getDistance = (point1, point2) => {
    const { x: x1, y: y1 } = point1;
    const { x: x2, y: y2 } = point2;

    const dx = x1 - x2;
    const dy = y1 - y2;

    const distance = Math.sqrt(dx * dx + dy * dy);

    return distance;
};

// Retorna un punto perteneciente a un arreglo de datos con
// la menor distancia al punto deseado
const getMinDistance = (point, points) => {
    let minDistance = 9999999;
    let minPoint = null;

    points.forEach((currentPoint) => {
        const currentDistance = getDistance(point, currentPoint);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            minPoint = currentPoint;
        }
    });

    return minPoint;
};

// Funcion recursiva que encuentra el punto de un arreglo
// con la distancia minima otro punto, borra dicho punto
// del arreglo inicial y lo añade a otro arreglo ordenado
const sortingByDistance = (data, initPoint, sortedData) => {
    if (data.length === 0) {
        return sortedData;
    }

    // Se calcula el punto del arreglo con la distancia minima al otro punto
    const pointWhitMinDistance = getMinDistance(initPoint, data);

    // Se añade el punto encontrado del arreglo de datos ordenado
    sortedData.push(pointWhitMinDistance);

    // Se elimina el punto encontrado del arreglo de datos
    data = data.filter((point) => point.name !== pointWhitMinDistance.name);

    return sortingByDistance(data, pointWhitMinDistance, sortedData);
};

// Se obtiene un el objeto correspondiente a un punto
// en el arreglo de datos segun el nombre
const getPointByName = (data, name) => {
    return data.find((point) => point.name === name);
};

// Ordena un arreglo de puntos a partir del tiempo
const sortingByTime = (data) => {
    return data.sort((point1, point2) => {
        return point2.time - point1.time;
    });
};

const testPoint = getPointByName(points, "D");
const testData = copyObject(points);
const out = sortingByDistance(testData, testPoint, []);
console.log(out);

console.log(sortingByTime(points));
