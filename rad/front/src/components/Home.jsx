import { Link } from "react-router-dom";

const Home = () => {
  return (
    <div
      className="flex flex-col items-center justify-center w-full text-white bg-gradient-to-r from-gray-700 via-gray-900 to-black"
      style={{ height: "90vh" }}
    >
      <div>
        <h1 className="text-4xl font-semibold text-center mb-6">RAD Project</h1>
        <p className="mx-28 text-xl text-center">
          Model–view–controller (MVC) is a software design pattern[1] commonly
          used for developing user interfaces that divides the related program
          logic into three interconnected elements. These elements are the
          internal representations of information (the model), the interface
          (the view) that presents information to and accepts it from the user,
          and the controller software linking the two.
          <Link to="/protected" className="text-blue-900">
            Learn More
          </Link>
        </p>
      </div>
    </div>
  );
};

export default Home;
