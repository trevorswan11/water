{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    utils.url = "github:numtide/flake-utils";
    zig-flake.url = "github:mitchellh/zig-overlay";
    zls-flake = {
      url = "github:zigtools/zls?ref=0.15.1";
      inputs.nixpkgs.follows = "nixpkgs";
      inputs.zig-overlay.follows = "zig-flake";
    };
  };

  outputs =
    {
      nixpkgs,
      utils,
      zig-flake,
      zls-flake,
      ...
    }:
    utils.lib.eachSystem
      [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ]
      (
        system:
        let
          pkgs = import nixpkgs {
            inherit system;

            overlays = [
              (final: prev: {
                zig = zig-flake.packages.${system}."0.15.2";
                zls = zls-flake.packages.${system}.default.overrideAttrs (old: {
                  nativeBuildInputs = (old.nativeBuildInputs or [ ]) ++ [ final.zig ];
                });
              })
            ];
          };
        in
        {
          devShells.default = pkgs.mkShell {
            nativeBuildInputs =
              with pkgs;
              [
                zig
                zls
                git
                python3
              ]
              ++ lib.optionals stdenv.isLinux [ kcov ];
          };
        }
      );
}
