type ApiResponse<T> = {
  status: "success" | "error";
  data: T;
  message?: string;
};

type User = {
  id: number;
  name: string;
  email: string;
};

type Product = {
  id: number;
  name: string;
  price: number;
};

type ApiResponseHandler<T> = {
  handleResponse: (response: ApiResponse<T>) => void;
};

type UserApiResponseHandler = ApiResponseHandler<User>;
type ProductApiResponseHandler = ApiResponseHandler<Product>;

const userHandler: UserApiResponseHandler = {
  handleResponse: (response) => {
    if (response.status === "success") {
      console.log("User data:", response.data);
    } else {
      console.error("Error:", response.message);
    }
  },
};

const productHandler: ProductApiResponseHandler = {
  handleResponse: (response) => {
    if (response.status === "success") {
      console.log("Product data:", response.data);
    } else {
      console.error("Error:", response.message);
    }
  },
};

const userResponse: ApiResponse<User> = {
  status: "success",
  data: { id: 1, name: "John Doe", email: "john.doe@example.com" },
};

const productResponse: ApiResponse<Product> = {
  status: "error",
  data: { id: 1, name: "Laptop", price: 999 },
  message: "Product not found",
};

userHandler.handleResponse(userResponse);
productHandler.handleResponse(productResponse);
