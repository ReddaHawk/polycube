/*
 * simplebridge API
 *
 * simplebridge API generated from simplebridge.yang
 *
 * API version: 1.0.0
 * Generated by: Swagger Codegen (https://github.com/swagger-api/swagger-codegen.git)
 */

package swagger

type Fdb struct {
	// Aging time of the filtering database (in seconds)
	AgingTime int32 `json:"aging-time,omitempty"`
	// Entry associated with the filtering database
	Entry []FdbEntry `json:"entry,omitempty"`
}
