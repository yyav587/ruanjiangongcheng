package tyut.practice.onlineDisk.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class UserDao extends Dao{

	/**
	 * ���ݴ�����û���(name)ȡ������
	 * @param  String name
	 * @return String password
	 */
	public String getPassWordByName(String name){
		String sql = "select password from user where name='" + name + "' or email='"+name+"'";
		Connection conn = null;
		Statement stat = null;
		try {  
            Class.forName(driver);//ָ����������  
            conn = DriverManager.getConnection(url, user, password);//��ȡ����  
            stat = conn.createStatement();
            ResultSet rs = stat.executeQuery(sql);
            
            if(rs.next()){
            	return rs.getString(1);
            }
            rs.close();
        } catch (Exception e) {  
            e.printStackTrace();  
        } finally{
        	try {
        		stat.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
		return null;
	}
	public String getNameByEmail(String email){
		String sql = "select name from user where email='" + email + "'";
		Connection conn = null;
		Statement stat = null;
		try {  
            Class.forName(driver);//ָ����������  
            conn = DriverManager.getConnection(url, user, password);//��ȡ����  
            stat = conn.createStatement();
            ResultSet rs = stat.executeQuery(sql);
            
            if(rs.next()){
            	return rs.getString(1);
            }
            rs.close();
        } catch (Exception e) {  
            e.printStackTrace();  
        } finally{
        	try {
        		stat.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
		return null;
	}
	public boolean addUser(String name, String password, String email){
		StringBuilder sql = new StringBuilder();
		sql.append("insert into user(name, password, email) values('");
		sql.append(name).append("', '").append(password).append("', '");
		sql.append(email).append("')");
		
		Connection conn = null;
		Statement stat = null;
		try {  
            Class.forName(driver);//ָ����������  
            conn = DriverManager.getConnection(url, user, this.password);//��ȡ����  
            stat = conn.createStatement();
            stat.execute(sql.toString());
            return true;
            
        } catch (Exception e) {  
            e.printStackTrace();  
        } finally{
        	try {
        		stat.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
		return false;
	}
	/**
	 * ���ݴ�����û���(id)�޸���Ӧ�û�������
	 * @param  String id,String password
	 * @return boolean 
	 */
	public boolean updatePasswordByName(String id,String password){
		StringBuilder sql = new StringBuilder();
		sql.append("update  user set password='").append(password).append("'");
		sql.append("where name='").append(id).append("'");
		Connection conn = null;
		Statement stat = null;
		try {  
            Class.forName(driver);//ָ����������  
            conn = DriverManager.getConnection(url, user, this.password);//��ȡ����  
            stat = conn.createStatement();
            stat.execute(sql.toString());
            return true;
            
        } catch (Exception e) {  
            e.printStackTrace();  
        } finally{
        	try {
        		stat.close();
				conn.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        }
		return false;
	}
}
