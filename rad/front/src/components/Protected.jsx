import model from "../assets/radModel.webp";
import controller from "../assets/radController.webp";
import view from "../assets/radView.webp";

const Protected = () => {
  return (
    <div className="w-full text-white bg-gradient-to-r from-gray-700 via-gray-900 to-black">
      <div
        className="flex flex-wrap
     md:flex-nowrap"
      >
        <div className="border rounded-lg p-2 mt-16">
          <h1 className="font-bold text-4xl">view</h1>
          <p>
            The view is responsible for presenting the user interface to the
            user. It displays the data from the model to the user and captures
            user input. The view component is designed to be as passive as
            possible, meaning it should not contain any business logic. Instead,
            it focuses on rendering the user interface based on the data
            provided by the model.
          </p>
        </div>
        <div className="border rounded-lg p-2 mt-16 m-3">
          <h1 className="font-bold text-4xl">controller</h1>
          <p>
            The controller acts as an intermediary between the model and the
            view. It handles user input, processes requests, and updates the
            model and view accordingly. The controller component interprets user
            actions (e.g., clicks, form submissions) and triggers changes in the
            model or view. It ensures that the model and view remain independent
            of each other.
          </p>
        </div>

        <div className="border rounded-lg p-2 mt-16">
          <h1 className="font-bold text-4xl">model</h1>
          <p>
            The model represents the data and business logic of the application.
            It is responsible for managing the data, processing business rules,
            and interacting with the database. The model component does not
            depend on the user interface or the controller.
          </p>
        </div>
      </div>
      <div className="pb-6 flex flex-col items-center">
        <p className="font-bold text-lg m-2 text-center mt-12">Model</p>
        <img src={model} className="border rounded object-cover w-[70%]" />
        <p className="font-bold text-lg m-2 text-center mt-12">View</p>
        <img src={view} className="border rounded" />
        <p className="font-bold text-lg m-2 text-center mt-12">Controller</p>
        <img src={controller} className="border rounded" />
      </div>
    </div>
  );
};

export default Protected;
