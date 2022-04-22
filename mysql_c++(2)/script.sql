CREATE TABLE `db_empresa`.`proveedores` (
  `id_proveedores` INT NOT NULL AUTO_INCREMENT,
  `proveedor` VARCHAR(60) NULL,
  `nit` VARCHAR(12) NULL,
  `direccion` VARCHAR(80) NULL,
  `telefono` VARCHAR(25) NULL,
  PRIMARY KEY (`id_proveedores`));
  
  